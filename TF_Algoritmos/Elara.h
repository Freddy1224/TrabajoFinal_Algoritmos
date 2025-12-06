#pragma once
#include "Entidad.h"
#include <vector>
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace TFAlgoritmos {
    public ref class Elara : public Entidad {
    public:
        Elara(int x, int y) : Entidad(x, y, "imagenes/elara.png") {
            
            ancho = imagen->Width / 8;
            alto = imagen->Height / 4;
            dx = 12;
            dy = 12;
        }

        void Mover(bool w, bool s, bool a, bool d, int limiteMapaW, int limiteMapaH, List<Rectangle>^ obstaculos) {
            int futuroX = x;
            int futuroY = y;
            bool seMueve = false;

            if (a) { futuroX -= dx; indiceY = 3; seMueve = true; }
            if (d) { futuroX += dx; indiceY = 1; seMueve = true; }
            if (w) { futuroY -= dy; indiceY = 2; seMueve = true; }
            if (s) { futuroY += dy; indiceY = 0; seMueve = true; }

            
            if (futuroX < 0 || futuroX + ancho > limiteMapaW || futuroY < 0 || futuroY + alto > limiteMapaH) return;

          

            int hitAncho = ancho / 2;       
            int hitAlto = alto / 3;         
            int hitX = futuroX + (ancho / 4); 
            int hitY = futuroY + (alto - hitAlto);

            Rectangle futuroHitbox = Rectangle(hitX, hitY, hitAncho, hitAlto);

            
            for (int i = 0; i < obstaculos->Count; i++) {
                if (futuroHitbox.IntersectsWith(obstaculos[i])) return;
            }

            
            x = futuroX;
            y = futuroY;

            if (seMueve) {
                indiceX++;
                if (indiceX > 7) indiceX = 0;
            }
        }

        
        Rectangle GetHitbox() {
            int hitAncho = ancho / 2;
            int hitAlto = alto / 3;
            int hitX = x + (ancho / 4);
            int hitY = y + (alto - hitAlto);

            return Rectangle(hitX, hitY, hitAncho, hitAlto);
        }

        
        void Dibujar(Graphics^ g, int camX, int camY) override {
            int anchoFrame = imagen->Width / 8;
            int altoFrame = imagen->Height / 4;
            Rectangle porcion = Rectangle(indiceX * anchoFrame, indiceY * altoFrame, anchoFrame, altoFrame);
            Rectangle destino = Rectangle(x - camX, y - camY, ancho, alto);

            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);

            
        }
    };
}