#include "iostream"
#include "Arco.h"
#include "Grafo.h"
#include "list"
#include "vector"
#include "stack"

using namespace std;

struct datos_dearcos{           //clasifica los arcos
    int origen;
    int destino;
    char tipo;
};

void imprimir_lista_arcos(list<Arco> una_lista){

    if (!una_lista.empty()){
    	cout << " D  C" << endl;
    	list<Arco>::iterator iterador= una_lista.begin();
    	while (iterador != una_lista.end()) {
    		Arco un_arco= *iterador;
    		cout << "(" << un_arco.Devolver_destino() << ", " << un_arco.Devolver_costo() << ")" << endl;
    		iterador++;
    	}
    	cout << endl;
    }
}

void imprimir_lista_vertices(list<int> una_lista){
    if (!una_lista.empty()){
        //cout << endl;
        list<int>::iterator iterador= una_lista.begin();
        while (iterador != una_lista.end()) {
            cout << *iterador << "  ";
            iterador++;
        }
        cout << endl;
    }
}

void imprimir_grafo(Grafo &un_grafo){
    cout << endl << endl;

    list<int> lista_vertices;
    un_grafo.devolver_vertices(lista_vertices);

    int longitud= un_grafo.devolver_longitud();
    list<Arco> una_lista_arcos;
    
    for (int i=0; i< longitud; i++){
        cout << endl;
        un_grafo.devolver_adyacentes(i, una_lista_arcos);
        list<Arco>::iterator iterador= una_lista_arcos.begin();
        while (iterador != una_lista_arcos.end()) {
            Arco arko= *iterador;
            int destino= arko.Devolver_destino();

            if (destino<i){
            
                // se posiciona en el vertice destino
                for(int j=1; j<destino*3; j++)
                    cout << " ";
                cout << " ";
                for(int k=destino*3; k<=i*3; k++)
                    cout << "«";            
            }else if (destino == i){
                // se posiciona en el vertice destino
                for(int j=1; j<destino*3; j++)
                    cout << " ";
                cout << "↓" << endl;
            }
            iterador++;
        }    
    }    

    imprimir_lista_vertices(lista_vertices);

    for (int i=0; i< longitud; i++){
        un_grafo.devolver_adyacentes(i, una_lista_arcos);
        list<Arco>::iterator iterador= una_lista_arcos.begin();
        while (iterador != una_lista_arcos.end()) {
            Arco arko= *iterador;
            int destino= arko.Devolver_destino();

            if (destino>i){
                // se posiciona en el vertice origen
                cout << " ";
                for(int j=1; j<i*3; j++)
                    cout << " ";
            
                // imprime un arco y va al renglon siguiente
                for(int k=i*3; k<destino*3; k++)
                    cout << "»";
                cout << " " << endl;                

            }
            iterador++;
        }        
    }

}

void imprimir_menu(){
	cout << "                         que desea hacer?" << endl;
	cout << "o-----------------------------------------------------------------------o" << endl;
	cout << "| 0- Salir                      |                                       |" << endl;
    cout << "| 1- Agregar un Arco            |  8- Agregar Vertice                   |" << endl;
    cout << "| 2- Eliminar un Arco           |  9- Eliminar Vertice                  |" << endl;
    cout << "| 3- Ver el Costo de un Arco    | 10- ver Cantidad de Vertices          |" << endl;
    cout << "| 4- Existe Arco?               | 11- el Grafo es vacio (vertices=0)?   |" << endl;
    cout << "| 5- Modificar el Costo Arco    | 12- existe vertice?                   |" << endl;
    cout << "| 6- ver Arcos Entrantes        | 13- Listar Vertices del Grafo         |" << endl;
    cout << "| 7- ver Arcos Adyacentes       |                                       |" << endl;
    cout << "------------------------------------------------------------------------o" << endl;
    cout << "| 14- Imprimir el GRAFO         | 16- Clasificar Arcos / aCiclicidad    |" << endl;
    cout << "| 15- DFS                       | 17- Orden Topologico                  |" << endl;
    cout << "o-----------------------------------------------------------------------o" << endl;
}

void DFS_visit(Grafo &un_grafo, int vertice_actual, int &tiempo, vector<char> &color, vector<int> &tiempo_inicial, vector<int> &tiempo_final, vector<int> &predecesores, vector<datos_dearcos> &listado, stack<int>&topologia){

    datos_dearcos este_arco;
    tiempo++;
    // lo pinta de gris
    color[vertice_actual]= 'G';
    tiempo_inicial[vertice_actual]= tiempo;
    //cout << "vertice " << vertice_actual << " --> GRIS --> tiempo_inicial " << tiempo << endl;

    // trae vertices adyacentes
    list<Arco> una_lista_arcos;
    un_grafo.devolver_adyacentes(vertice_actual, una_lista_arcos);
    
    // itera sobre los vertices adyacentes
    list<Arco>::iterator un_iterador= una_lista_arcos.begin();
    while (un_iterador != una_lista_arcos.end()){
        Arco un_arco= *un_iterador;
        int un_adyacente= un_arco.Devolver_destino();
        este_arco.origen= vertice_actual;
        este_arco.destino= un_adyacente;
        
        // clasifica los arcos y si es blanco lo inspecciona!
        if (color[un_adyacente] == 'G'){
            este_arco.tipo= 'B';
            listado.push_back(este_arco);
        }
        if (color[un_adyacente] == 'N'){
            if (tiempo_inicial[vertice_actual] < tiempo_inicial[un_adyacente]){
                este_arco.tipo= 'F';
            }else{
                este_arco.tipo= 'C';
            }
            listado.push_back(este_arco);
        }
        if (color[un_adyacente] == 'B'){
            predecesores[un_adyacente]= vertice_actual;
            este_arco.tipo= 'T';
            listado.push_back(este_arco);
            DFS_visit(un_grafo, un_adyacente, tiempo, color, tiempo_inicial, tiempo_final, predecesores, listado, topologia);
        }
        un_iterador++;
    }

    // graba el tiempo de finalizacion del vertice_actual
    // lo pinta de negro
    tiempo++;
    tiempo_final[vertice_actual]= tiempo;
    color[vertice_actual]= 'N';
    topologia.push(vertice_actual);
}

void DFS(Grafo &un_grafo, vector<datos_dearcos> &listado, stack<int> &topologia){
    // para todos los vertices: 
    // arma vector colores: B.lanco -> sin visitar, G.ris -> visitado, N.egro-> completo
    // arma vector tiempo visita
    // arma vector tiempo fin
    std::vector<char> color;
    std::vector<int> predecesores;
    std::vector<int> tiempo_inicial; 
    std::vector<int> tiempo_final;
    int tiempo= 0;

    // vacia los contenedores de las respuestas del dfs (arcos y topologia)
    listado.clear();
    
    while (!topologia.empty())
        topologia.pop();
    

    // consigue los vertices del grafo:
    list<int> lista_vertices;
    un_grafo.devolver_vertices(lista_vertices);
    
    // pone c/vertice en color Blanco e inicializa tiempos
    list<int>::iterator iterador= lista_vertices.begin();
    while(iterador != lista_vertices.end()){
        color.push_back('B');
        tiempo_inicial.push_back(-1);
        tiempo_final.push_back(-1);
        predecesores.push_back(-1);
        iterador++;
    }

    // recorre c/vertice
    iterador= lista_vertices.begin();
    while(iterador != lista_vertices.end()){
        int vertice_actual= *iterador;
        if (color[vertice_actual] == 'B')
            DFS_visit(un_grafo, vertice_actual, tiempo, color, tiempo_inicial, tiempo_final, predecesores, listado, topologia);

        iterador++;
    }

    // imprime el grafo
    imprimir_grafo(un_grafo);

    // muestra info obtenida
    cout << "vertice" << "    padre" << "    color" <<"    t. inicial" << "    t.final" << endl;
    for (int i=0; i<lista_vertices.size(); i++){
        cout << i << "           " << predecesores[i] << "        " << color[i] <<  "         " << tiempo_inicial[i] <<  "         " << tiempo_final[i] << endl;
    }

    cout << endl;


    

}





  /////////////////////////////////////////////////////////////
 //                     M A I N                             //
/////////////////////////////////////////////////////////////

int main(){
    int vertices, opcion, vertice, origen, destino, costo;
    list<int> listado_vertices;
    list<Arco> lista_arcos;
                    
    std::vector<datos_dearcos> listado; // es requerimiento del DFS para aciclicidad
    stack<int> topologia; // es requerimiento del DFS para Ordenamiento Topologico



    /*
    cout << endl << "Ingrese cantidad de vertices: ";
    cin >> vertices;
    Grafo un_grafo(vertices);
    */
    Grafo un_grafo(6);
    un_grafo.agregar_arco(0, 1, 99);
    un_grafo.agregar_arco(0, 3, 99);
    un_grafo.agregar_arco(1, 4, 99);
    un_grafo.agregar_arco(4, 3, 99);
    un_grafo.agregar_arco(3, 1, 99);
    un_grafo.agregar_arco(2, 4, 99);
    un_grafo.agregar_arco(2, 5, 99);
    un_grafo.agregar_arco(5, 5, 99);

    cout << endl << "Grafo de " << un_grafo.devolver_longitud() << " vertices creado" << endl << endl;

    //imprimir_grafo(un_grafo);

    imprimir_menu();
    cin >> opcion;

    while (opcion != 0){
        switch (opcion){
            case 1:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout << "Ingrese Costo del arco: ";
                cin >> costo;
                un_grafo.agregar_arco(origen, destino, costo);
                cout << endl << "Se agregó el arco (" << origen << ", " << destino << ", " << costo << ")" << endl;
            }
                break;
            
            case 2:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                un_grafo.eliminar_arco(origen, destino);
                cout << endl <<  "Se Eliminó el arco (" << origen << ", " << destino << ")" << endl;    
            }
                break;
            
            case 3:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << un_grafo.costo_arco(origen, destino) << endl;
            }
                break;
            
            case 4:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                if (un_grafo.existe_arco(origen, destino))
                    cout << endl <<  "(" << origen << ", " << destino << ") Existe" << endl;
                else
                    cout << endl <<  "(" << origen << ", " << destino << ") NO Existe" << endl;

            }
                break;
            
            case 5:{
                cout << "Ingrese Origen del arco: ";
                cin >> origen;
                cout << "Ingrese Destino del arco: ";
                cin >> destino;
                cout << "Ingrese el Nuevo Costo del arco: ";
                cin >> costo;
                un_grafo.modificar_costo_arco(origen, destino, costo);
                cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << un_grafo.costo_arco(origen, destino) << endl;
            }
            /*
            case 6:{
                cout << "Ingrese el Vertice para ver Arcos Entrantes: ";
                cin >> vert;
                un_grafo.Devolver_entrantes(vert, lista_arcos);
                imprimir_lista(lista_arcos);
            }
                break;
            */
            case 7:{
                cout << "Ingrese el Vertice para ver Arcos Salientes: ";
                cin >> vertice;
                un_grafo.devolver_adyacentes(vertice, lista_arcos);
                imprimir_lista_arcos(lista_arcos);
            }
                break;
            
            case 8:{
                // si quisiera algun nombre en especial deberia
                // llevar aparte otro arreglo con los nombres y listo
                // por defecto se agrega un vertice al final:
                
                un_grafo.agregar_vertice(0);
                cout << endl <<  "1 Vertice Agregado! " << endl;
                cout << "nueva Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            
            case 9:{
                // cout << "Ingrese el N° de Vertice a Eliminar: ";
                // cin >> vert;
                // un_grafo.Eliminar_vertice(vert);
                cout << endl << "metodo aun no implementado! " << endl;
                // cout << endl << "Vertice Eliminado! " << endl;
                cout << "Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            
            case 10:{
                cout << endl <<  "Cantidad de vertices: " << un_grafo.devolver_longitud() << endl;
            }
                break;
            case 11:{
                if (un_grafo.esta_vacio())
                    cout << "NO existen vertices. Grafo VACIO" << endl;
                else
                    cout << "Existen vertices. Grafo NO vacio" << endl;
            }
                break;
            case 12:{
                cout << "ingrese en vertice a verificar (0...n): ";
                cin >> vertice;
                cout << endl;
                if (un_grafo.existe_vertice(vertice))
                    cout << "El vertice " << vertice << " Existe!" << endl;
                else
                    cout << "El vertice " << vertice << " NO Existe!" << endl;
            }
                break;
            case 13:{
                un_grafo.devolver_vertices(listado_vertices);
                imprimir_lista_vertices(listado_vertices);
            }
                break;
            case 14:{
                imprimir_grafo(un_grafo);
            }
                break;
            case 15:{
                DFS(un_grafo, listado, topologia);
            }
                break;
            case 16:{
                DFS(un_grafo, listado, topologia);
                cout << "origen" << "    destino" << "    tipo de arco" << "     ciclo?" <<endl;
                for (datos_dearcos i : listado){
                    cout << i.origen << "          " << i.destino << "          " << i.tipo;     
                    if (i.tipo == 'B')
                        cout << "                Si " << endl;
                    else
                        cout << "                No " << endl;
                }
                
            }
                break;
            case 17:{
                DFS(un_grafo, listado, topologia);
                cout << endl << "Ordenamiento Topologico" << endl;
                while(!topologia.empty()){
                    cout << topologia.top() << "  ";
                    topologia.pop();
                }
                cout << endl;
            }
                break;
            default:{
                cout <<  endl << "Opción invalida\n" << "Ingrese una nueva opción\n";
            }
            break;

        }

        cout << endl << "Presione <ENTER> para continuar.." << endl;
        cin.ignore();
        cin.ignore();

        imprimir_menu();
        cin >> opcion;
    }



	return 0;
}
