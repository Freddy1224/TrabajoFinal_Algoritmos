#pragma once
#include "Entidad.h"
#include <vector>
using namespace System::Collections::Generic;

namespace TFAlgoritmos {
    public ref class Elara : public Entidad {
    public:
        Elara(int x, int y) : Entidad(x, y, "imagenes/elara.png") {
            // Cálculo automático de tamaño (Igual que Kael)
            ancho = imagen->Width / 8;  // 32 px
            alto = imagen->Height / 4;  // 52 px approx
            dx = 8;
            dy = 8;
        }

        void Mover(bool w, bool s, bool a, bool d, int limiteW, int limiteH, List<Rectangle>^ obstaculos) {
            int futuroX = x;
            int futuroY = y;
            bool seMueve = false;

            // Direcciones (Ajustadas a tu sprite sheet: 0=Abajo, 1=Izq, 2=Der, 3=Arr)
            if (a) { futuroX -= dx; indiceY = 3; seMueve = true; }
            if (d) { futuroX += dx; indiceY = 1; seMueve = true; }
            if (w) { futuroY -= dy; indiceY = 2; seMueve = true; }
            if (s) { futuroY += dy; indiceY = 0; seMueve = true; }

            // Límites de pantalla
            if (futuroX < 0 || futuroX + ancho > limiteW || futuroY < 0 || futuroY + alto > limiteH) return;

            // Colisión con paredes (Estantes)
            Rectangle futuroRect = Rectangle(futuroX, futuroY, ancho, alto);
            for (int i = 0; i < obstaculos->Count; i++) {
                if (futuroRect.IntersectsWith(obstaculos[i])) return;
            }

            x = futuroX;
            y = futuroY;

            // Animación
            if (seMueve) {
                indiceX++;
                if (indiceX > 7) indiceX = 0;
            }
        }
    };
}