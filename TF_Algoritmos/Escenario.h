#pragma once
#include "Entidad.h"

namespace TFAlgoritmos {
    public ref class Escenario : public Entidad {
    private:
        int contadorTiempo;

    public:
       
        Escenario() : Entidad(0, 0, "imagenes/fondo_lab.png") {
            
            ancho = 1600;
            alto = 1600;
            contadorTiempo = 0;
        }

        void Animar() {
            contadorTiempo++;
            // Velocidad de parpadeo de luces
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

        // DIBUJAR CON CÁMARA
        void Dibujar(Graphics^ g, int camX, int camY) override {
            // Calculamos el recorte en la imagen gigante
            int srcX = (indiceX * 1600) + camX;
            int srcY = (indiceY * 1600) + camY;

            // Recortamos solo lo que ve la cámara (800x800)
            Rectangle porcion = Rectangle(srcX, srcY, 800, 800);
            Rectangle destino = Rectangle(0, 0, 800, 800);

            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }
    };
}