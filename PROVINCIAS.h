#ifndef PROVINCIAS_H_INCLUDED
#define PROVINCIAS_H_INCLUDED

class Provincia{
private:
    char nombre[40];
    char codigo_provincias[5];
    int idprovincia;
public:
    void setNombre(const char *);
    void setCodigo_provincias(const char *);
    void setIdprovincia(int);

    const char *getNombre();
    const char *getCodigo_provincias();
    int getIdprovincia();

    void cargar();
    void mostrar();
};

#endif // PROVINCIAS_H_INCLUDED
