#ifndef PROVINCIAS_H_INCLUDED
#define PROVINCIAS_H_INCLUDED

class Provincia{
private:
    char nombre[40];
    char codigo_provincias[5];
    int idprovincia;
public:
    void setNombre(const char *);
    void setcodigo_provincias(const char *);
    void setidprovincia(int);

    const char *getNombre();
    const char *getcodigo_provincias();
    int getidprovincia();

    void cargar();
    void mostrar();
};

#endif // PROVINCIAS_H_INCLUDED
