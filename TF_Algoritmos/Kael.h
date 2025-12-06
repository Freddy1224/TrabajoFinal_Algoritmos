#pragma once
#include "Entidad.h"
#include <vector>
using namespace System::Collections::Generic;

namespace TFAlgoritmos {
    public ref class Kael : public Entidad {
    private:
        int voluntad;
        int logica;

    public:
        Kael(int x, int y) : Entidad(x, y, "imagenes/kael.png") {
            
            ancho = imagen->Width / 8;
            alto = imagen->Height / 4;
            dx = 12; 
            dy = 12;
            voluntad = 0;
            logica = 0;
        }

       
        void Mover(bool w, bool s, bool a, bool d, int limiteW, int limiteH, List<Rectangle>^ obstaculos) {
            int futuroX = x;
            int futuroY = y;
            bool seMueve = false;

            if (a) { futuroX -= dx; indiceY = 3; seMueve = true; } // Izq
            if (d) { futuroX += dx; indiceY = 1; seMueve = true; } // Der
            if (w) { futuroY -= dy; indiceY = 2; seMueve = true; } // Arr
            if (s) { futuroY += dy; indiceY = 0; seMueve = true; } // Aba

            // Limites del mapa
            if (futuroX < 0 || futuroX + ancho > limiteW || futuroY < 0 || futuroY + alto > limiteH) return;

            // Colisiones con paredes
            Rectangle futuroRect = Rectangle(futuroX, futuroY, ancho, alto);
            for (int i = 0; i < obstaculos->Count; i++) {
                if (futuroRect.IntersectsWith(obstaculos[i])) return;
            }

            x = futuroX;
            y = futuroY;

            if (seMueve) {
                indiceX++;
                if (indiceX > 7) indiceX = 0;
            }
        }

        
        void Dibujar(Graphics^ g, int camX, int camY) override {
            int anchoFrame = imagen->Width / 8;
            int altoFrame = imagen->Height / 4;
            Rectangle porcion = Rectangle(indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);

            // Restar camara
            Rectangle destino = Rectangle(x - camX, y - camY, ancho, alto);

            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }

        void AumentarVoluntad() { voluntad++; }
        int GetVoluntad() { return voluntad; }
    };
}