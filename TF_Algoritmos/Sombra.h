#pragma once
#include "Entidad.h"
#include <vector>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace TFAlgoritmos {
    public ref class Sombra : public Entidad {
    private:
        int velocidad;
        int rangoVision;
        int startX, startY;

    public:
        Sombra(int x, int y) : Entidad(x, y, "imagenes/sombra.png") {
          
            ancho = imagen->Width / 4;
            alto = imagen->Height / 4;

            velocidad = 1;    
            rangoVision = 350;

            dx = 0;
            dy = 0;

            
            startX = x;
            startY = y;
        }

        void Perseguir(int objetivoX, int objetivoY, List<Rectangle>^ obstaculos, Rectangle hitboxElara) {
            
            Rectangle miHitbox = GetHitbox();
            int centroX = miHitbox.X + miHitbox.Width / 2;
            int centroY = miHitbox.Y + miHitbox.Height / 2;

            int destX = hitboxElara.X + hitboxElara.Width / 2;
            int destY = hitboxElara.Y + hitboxElara.Height / 2;

            
            int catetoX = destX - centroX;
            int catetoY = destY - centroY;
            long distanciaCuadrado = (long)catetoX * catetoX + (long)catetoY * catetoY;
            long rangoCuadrado = (long)rangoVision * rangoVision;

           
            if (distanciaCuadrado < rangoCuadrado) {
                // Moverse hacia Elara
                if (centroX < destX) dx = velocidad;
                else if (centroX > destX) dx = -velocidad;
                else dx = 0;

                if (centroY < destY) dy = velocidad;
                else if (centroY > destY) dy = -velocidad;
                else dy = 0;

                MoverConColisiones(obstaculos);
                Animar();
            }
            
            else {
                bool llegoX = false;
                bool llegoY = false;

                
                if (x < startX - velocidad) dx = velocidad;
                else if (x > startX + velocidad) dx = -velocidad;
                else { dx = 0; llegoX = true; x = startX; } 

                
                if (y < startY - velocidad) dy = velocidad;
                else if (y > startY + velocidad) dy = -velocidad;
                else { dy = 0; llegoY = true; y = startY; }

               
                if (!llegoX || !llegoY) {
                    MoverConColisiones(obstaculos);
                    Animar();
                }
                else {
                    indiceX = 0; 
                }
            }
        }

        
        Rectangle GetHitbox() {
            int hitW = ancho / 2;
            int hitH = alto / 2;
            int hitX = x + (ancho / 4);
            int hitY = y + (alto / 2);
            return Rectangle(hitX, hitY, hitW, hitH);
        }

        
        void Dibujar(Graphics^ g, int camX, int camY) {
            Rectangle porcion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
            Rectangle destino = Rectangle(x - camX, y - camY, ancho, alto);

            g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::NearestNeighbor;
            g->DrawImage(imagen, destino, porcion, GraphicsUnit::Pixel);
        }

    private:
        void MoverConColisiones(List<Rectangle>^ obstaculos) {
            int hitW = ancho / 2;
            int hitH = alto / 2;
            int offsetX = ancho / 4;
            int offsetY = alto / 2;

            // X
            int futuroX = x + dx;
            Rectangle rFuturoX = Rectangle(futuroX + offsetX, y + offsetY, hitW, hitH);
            bool chocoX = false;
            for (int i = 0; i < obstaculos->Count; i++) {
                if (rFuturoX.IntersectsWith(obstaculos[i])) { chocoX = true; break; }
            }
            if (!chocoX) x = futuroX;

            // Y
            int futuroY = y + dy;
            Rectangle rFuturoY = Rectangle(x + offsetX, futuroY + offsetY, hitW, hitH);
            bool chocoY = false;
            for (int i = 0; i < obstaculos->Count; i++) {
                if (rFuturoY.IntersectsWith(obstaculos[i])) { chocoY = true; break; }
            }
            if (!chocoY) y = futuroY;
        }

        void Animar() {
            int velX = dx; if (velX < 0) velX *= -1;
            int velY = dy; if (velY < 0) velY *= -1;

            if (velX > velY) {
                if (dx > 0) indiceY = 1; // Derecha
                else indiceY = 3;        // Izquierda
            }
            else {
                if (dy > 0) indiceY = 0; // Abajo
                else indiceY = 2;        // Arriba
            }

            indiceX++;
            if (indiceX > 3) indiceX = 0;
        }
    };
}