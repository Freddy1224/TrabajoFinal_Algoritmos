#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Escenario2 : public Entidad {
    private:
        int contadorTiempo;

    public:
        Escenario2() : Entidad(0, 0, "imagenes/fondo_biblio.png") {
            ancho = 800;
            alto = 800;
            contadorTiempo = 0;
        }

        void Animar() {
            contadorTiempo++;
            // Animacion del fondo 
            if (contadorTiempo > 100) {
                indiceX++;
                if (indiceX > 1) {
                    indiceX = 0;
                    indiceY++;
                    if (indiceY > 1) indiceY = 0;
                }
                contadorTiempo = 0;
            }
        }

        void Dibujar(Graphics^ g) override {
            Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle destino = Rectangle(0, 0, ancho, alto);
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }
    };
}