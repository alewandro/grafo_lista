#ifndef ARCO_H
#define ARCO_H

template <typename un_tipo> 
	class Arco{
		public:
			Arco(const int o, const int d, const un_tipo c);
			virtual ~Arco();

			int Devolver_origen() const;
			int Devolver_destino() const;
			un_tipo Devolver_costo() const;

		private:
			int origen;
			int destino;
			un_tipo costo;

};

#endif