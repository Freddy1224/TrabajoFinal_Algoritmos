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
            dx = 8;
            dy = 8;
            voluntad = 0;
            logica = 0;
        }

        
        void Mover(bool w, bool s, bool a, bool d, int limiteW, int limiteH, List<Rectangle>^ obstaculos) {
            int futuroX = x;
            int futuroY = y;
            bool seMueve = false;

            
            if (a) { futuroX -= dx; indiceY = 3; seMueve = true; }
            if (d) { futuroX += dx; indiceY = 1; seMueve = true; }
            if (w) { futuroY -= dy; indiceY = 2; seMueve = true; }
            if (s) { futuroY += dy; indiceY = 0; seMueve = true; }

           
            if (futuroX < 0 || futuroX + ancho > limiteW || futuroY < 0 || futuroY + alto > limiteH) {
                return; 
            }

            
            Rectangle futuroRect = Rectangle(futuroX, futuroY, ancho, alto);

            for (int i = 0; i < obstaculos->Count; i++) {
                if (futuroRect.IntersectsWith(obstaculos[i])) {
                    return; 
                }
            }

          
            x = futuroX;
            y = futuroY;

            // animacion
            if (seMueve) {
                indiceX++;
                if (indiceX > 7) indiceX = 0;
            }
        }

        void AumentarVoluntad() { voluntad++; }
        int GetVoluntad() { return voluntad; }
    };
}