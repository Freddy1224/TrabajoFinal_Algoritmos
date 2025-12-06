#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Terminal : public Entidad {
    public:
        int id;
        bool activa;

        Terminal(int x, int y, int id) : Entidad(x, y, "imagenes/terminal.png") {
            this->id = id;
            this->activa = true;

            
            ancho = imagen->Width / 2;
            alto = imagen->Height;

            indiceX = 0; // Rojo
            indiceY = 0;
        }

        void Desactivar() {
            activa = false;
            indiceX = 1; 
        }

        
        void Dibujar(Graphics^ g, int camX, int camY) override {
            Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle destino = Rectangle(x - camX, y - camY, ancho, alto);

            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }
    };
}