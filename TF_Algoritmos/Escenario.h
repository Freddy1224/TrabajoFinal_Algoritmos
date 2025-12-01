#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Escenario : public Entidad {
    private:
        int contadorTiempo; // velocidad de animación del fondo

    public:
        Escenario() : Entidad(0, 0, "imagenes/fondo_lab.png") {
            ancho = 800; // tamaño de la ventana del juego
            alto = 800;
            contadorTiempo = 0;
        }

        void Animar() {
            contadorTiempo++;
            // frame cada 10 ciclos para que no parpadee muy rapido
            if (contadorTiempo > 10) {
                indiceX++;
                if (indiceX > 1) { 
                    indiceX = 0;
                    indiceY++;
                    if (indiceY > 1) { 
                        indiceY = 0;
                    }
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