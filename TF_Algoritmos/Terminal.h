#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Terminal : public Entidad {
    public:
        int id;       // iD del dialogo (1 al 5)
        bool activa;  // true = Roja (pendiente), false = Verde (hackeada)

        Terminal(int x, int y, int id) : Entidad(x, y, "imagenes/terminal.png") {
            this->id = id;
            this->activa = true;

            
            ancho = imagen->Width / 2;
            alto = imagen->Height;

            indiceX = 0; // 0 = Rojo
            indiceY = 0;
        }

        void Desactivar() {
            activa = false;
            indiceX = 1; 
        }

        
        void Dibujar(Graphics^ g) override {
            Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle destino = Rectangle(x, y, ancho, alto);
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }
    };
}