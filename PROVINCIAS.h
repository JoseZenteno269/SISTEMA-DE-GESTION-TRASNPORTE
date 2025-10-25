#ifndef PROVINCIAS_H_INCLUDED
#define PROVINCIAS_H_INCLUDED

class Provincia{
private:
    char nombre[30];
    int codigo_provincias;
public:
    void setNombre(const char *);
    void setcodigo_provincias(int);

    const char *getNombre();
    int getcodigo_provincias();

    void cargar();
    void mostrar();
};

#endif // PROVINCIAS_H_INCLUDED
