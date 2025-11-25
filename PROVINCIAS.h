#ifndef PROVINCIAS_H_INCLUDED
#define PROVINCIAS_H_INCLUDED

class Provincia{
private:
    char nombre[40];
    int idprovincia;
public:
    void setNombre(const char *);
    void setIdprovincia(int);

    const char *getNombre();
    int getIdprovincia();

    void cargar();
    void mostrar();
};

#endif // PROVINCIAS_H_INCLUDED
