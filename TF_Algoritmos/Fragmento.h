#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Fragmento : public Entidad {
    public:
        int id;      
        bool activo;  
        int tiempoAnimacion; 

        Fragmento(int x, int y, int id) : Entidad(x, y, "imagenes/fragmento.png") {
            this->id = id;
            this->activo = true;
            this->tiempoAnimacion = 0;

           
            ancho = imagen->Width / 4;
            alto = imagen->Height / 2;

            indiceX = 0;
            indiceY = 0;
        }

        
        void Animar() {
            tiempoAnimacion++;
            
            if (tiempoAnimacion > 10) {
                indiceX++;
                
                if (indiceX > 3) indiceX = 0;

                tiempoAnimacion = 0;
            }
        }

        void Desactivar() {
            activo = false;
        }

        void Dibujar(Graphics^ g, int camX, int camY) override {
            if (!activo) return;

            Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle destino = Rectangle(x - camX, y - camY, ancho, alto);

            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }

        Rectangle GetRectangulo() {
            return Rectangle(x, y, ancho, alto);
        }
    };
}