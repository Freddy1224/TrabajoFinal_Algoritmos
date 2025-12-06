#pragma once
using namespace System;
using namespace System::Drawing;

namespace TFAlgoritmos {
    public ref class Entidad {
    protected:
        int x, y;             // posicion
        int dx, dy;           // velocidad
        int ancho, alto;      // tamaño del frame
        int indiceX, indiceY; // para recorrer el sprite sheet
        Bitmap^ imagen;

    public:
        Entidad(int x, int y, String^ ruta) {
            this->x = x;
            this->y = y;
            this->dx = 0;
            this->dy = 0;
            this->indiceX = 0;
            this->indiceY = 0;

          
            try {
                imagen = gcnew Bitmap(ruta);
            }
            catch (...) {
                
                imagen = gcnew Bitmap(50, 50);
            }
        }

        virtual void Dibujar(Graphics^ g) {
            Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle destino = Rectangle(x, y, ancho, alto);
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }

        Rectangle GetRectangulo() {
            return Rectangle(x, y, ancho, alto);
        }

        int GetX() { return x; }
        int GetY() { return y; }
    };
}