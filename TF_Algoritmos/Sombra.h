#pragma once
#include "Entidad.h"
#include <vector>

using namespace System;
using namespace System::Collections::Generic;

namespace TFAlgoritmos {
    public ref class Sombra : public Entidad {
    private:
        int velocidad;
        int rangoVision;

    public:
        Sombra(int x, int y) : Entidad(x, y, "imagenes/sombra.png") {
            // Validación de imagen
            if (imagen->Width > 100) { ancho = 32; alto = 32; }
            else { ancho = imagen->Width; alto = imagen->Height; }

            velocidad = 1;
            rangoVision = 70;

            dx = 0;
            dy = 0;
        }

        void Perseguir(int objetivoX, int objetivoY, List<Rectangle>^ obstaculos) {
            // 1. Calcular centros
            int centroX = x + ancho / 2;
            int centroY = y + alto / 2;
            int destX = objetivoX + 16;
            int destY = objetivoY + 26;

            // 2. Distancia manual (Sin Raíz Cuadrada)
            int catetoX = destX - centroX;
            int catetoY = destY - centroY;

            // Distancia al cuadrado (Pitágoras simplificado)
            long distanciaCuadrado = (catetoX * catetoX) + (catetoY * catetoY);
            long rangoCuadrado = rangoVision * rangoVision;

            // 3. Decidir comportamiento
            if (distanciaCuadrado < rangoCuadrado) {
                // Dirección X
                if (centroX < destX) dx = velocidad;
                else if (centroX > destX) dx = -velocidad;
                else dx = 0;

                // Dirección Y
                if (centroY < destY) dy = velocidad;
                else if (centroY > destY) dy = -velocidad;
                else dy = 0;

                MoverConColisiones(obstaculos);
                Animar();
            }
            else {
                // Quieto
                dx = 0;
                dy = 0;
                indiceX = 0;
            }
        }

    private:
        void MoverConColisiones(List<Rectangle>^ obstaculos) {
            // Mover en X
            int futuroX = x + dx;
            Rectangle rFuturoX = Rectangle(futuroX, y, ancho, alto);
            bool chocoX = false;

            for (int i = 0; i < obstaculos->Count; i++) {
                if (rFuturoX.IntersectsWith(obstaculos[i])) {
                    chocoX = true; break;
                }
            }
            if (!chocoX) x = futuroX;

            // Mover en Y
            int futuroY = y + dy;
            Rectangle rFuturoY = Rectangle(x, futuroY, ancho, alto);
            bool chocoY = false;

            for (int i = 0; i < obstaculos->Count; i++) {
                if (rFuturoY.IntersectsWith(obstaculos[i])) {
                    chocoY = true; break;
                }
            }
            if (!chocoY) y = futuroY;
        }

        void Animar() {
            
            int velocidadX = dx;
            int velocidadY = dy;

            
            if (velocidadX < 0) velocidadX = velocidadX * -1;
            if (velocidadY < 0) velocidadY = velocidadY * -1;

            
            if (velocidadX > velocidadY) {
                
                if (dx > 0) indiceY = 2; 
                else indiceY = 1;       
            }
            else {
                
                if (dy > 0) indiceY = 0; 
                else indiceY = 3;       
            }

            
            indiceX++;
            if (indiceX > 3) indiceX = 0;
        }
    };
}