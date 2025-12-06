#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Escenario2 : public Entidad {
    private:
        int contadorTiempo;

    public:
        Escenario2() : Entidad(0, 0, "imagenes/fondo_biblio.png") {
            
            ancho = 1600;
            alto = 1600;
            contadorTiempo = 0;
        }

        void Animar() {
            contadorTiempo++;
            if (contadorTiempo > 20) {
                indiceX++;
                if (indiceX > 1) {
                    indiceX = 0;
                    indiceY++;
                    if (indiceY > 1) indiceY = 0;
                }
                contadorTiempo = 0;
            }
        }

        
        void Dibujar(Graphics^ g, int camX, int camY) override {
            int srcX = (indiceX * 1600) + camX;
            int srcY = (indiceY * 1600) + camY;

            Rectangle porcion = Rectangle(srcX, srcY, 800, 800);
            Rectangle destino = Rectangle(0, 0, 800, 800);

            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }
    };
}