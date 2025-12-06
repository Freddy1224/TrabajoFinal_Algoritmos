#pragma once
#include "Escenario2.h"
#include "Elara.h"
#include "Sombra.h"
#include "Fragmento.h" 
#include <vector>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;

namespace TFAlgoritmos {
    public ref class ControladoraNivel2 {
    private:
        Escenario2^ escenario;
        Elara^ elara;
        List<Rectangle>^ obstaculos;
        List<Sombra^>^ sombras;
        List<Fragmento^>^ fragmentos;
        int fragmentosRecogidos;

        
        int camX, camY;

    public:
        ControladoraNivel2() {
            escenario = gcnew Escenario2();
            elara = gcnew Elara(420, 1410);
            obstaculos = gcnew List<Rectangle>();
            sombras = gcnew List<Sombra^>();
            fragmentos = gcnew List<Fragmento^>(); 
            fragmentosRecogidos = 0;

            
            obstaculos->Add(Rectangle(0, 0, 1600, 100));    // Techo
            obstaculos->Add(Rectangle(0, 1500, 1600, 100)); // Suelo
            obstaculos->Add(Rectangle(0, 0, 61, 254));    // Izquierda
            obstaculos->Add(Rectangle(0, 468, 61, 940));

            obstaculos->Add(Rectangle(1500, 0, 100, 1600)); // Derecha
            obstaculos->Add(Rectangle(0, 1500, 1600, 100));
            obstaculos->Add(Rectangle(60, 100, 400, 145));
            obstaculos->Add(Rectangle(62, 572, 50, 550));

            obstaculos->Add(Rectangle(321, 30, 380, 350));
            obstaculos->Add(Rectangle(580, 30, 330, 220));
            obstaculos->Add(Rectangle(916, 100, 24, 300));
            obstaculos->Add(Rectangle(960, 100, 700, 120));
            obstaculos->Add(Rectangle(1508, 410, 46, 160));
            obstaculos->Add(Rectangle(1108, 488, 154, 80));
            obstaculos->Add(Rectangle(1108, 1240, 200, 70));
            obstaculos->Add(Rectangle(50, 1240, 266, 166));
            obstaculos->Add(Rectangle(832, 1241, 60, 266));
            obstaculos->Add(Rectangle(579, 1242, 314, 165));
            obstaculos->Add(Rectangle(788, 600, 800, 420));
            obstaculos->Add(Rectangle(788, 540, 150, 100));
            obstaculos->Add(Rectangle(385, 572, 400, 510));
            obstaculos->Add(Rectangle(1500, 1100, 46, 400));

            //SOMBRAs
            sombras->Add(gcnew Sombra(210, 1010));
            sombras->Add(gcnew Sombra(1200, 1140));
            sombras->Add(gcnew Sombra(400, 500));
            sombras->Add(gcnew Sombra(940, 300));
            sombras->Add(gcnew Sombra(666, 1400));
            sombras->Add(gcnew Sombra(300, 1200));

            //libros
            
            fragmentos->Add(gcnew Fragmento(1400, 200, 1));  
            fragmentos->Add(gcnew Fragmento(200, 1400, 2));  
            fragmentos->Add(gcnew Fragmento(775, 293, 3));   
            fragmentos->Add(gcnew Fragmento(1400, 1400, 4)); 
            fragmentos->Add(gcnew Fragmento(200, 200, 5));   
        }

        void MoverTodo(bool w, bool s, bool a, bool d) {
            escenario->Animar();
            elara->Mover(w, s, a, d, 1600, 1600, obstaculos);

            
            camX = elara->GetX() - 400 + (elara->GetRectangulo().Width / 2);
            camY = elara->GetY() - 400 + (elara->GetRectangulo().Height / 2);
            if (camX < 0) camX = 0; if (camY < 0) camY = 0;
            if (camX > 1600 - 800) camX = 800; if (camY > 1600 - 800) camY = 800;

            // Mover Sombras
            for (int i = 0; i < sombras->Count; i++) {
                sombras[i]->Perseguir(elara->GetX(), elara->GetY(), obstaculos, elara->GetHitbox());
            }

            
            for (int i = 0; i < fragmentos->Count; i++) {
                if (fragmentos[i]->activo) {
                    fragmentos[i]->Animar();
                }
            }

            VerificarColisiones();
        }

        
        int VerificarColisiones() {
            Rectangle rElara = elara->GetHitbox();

            
            for (int i = 0; i < sombras->Count; i++) {
                if (rElara.IntersectsWith(sombras[i]->GetHitbox())) {
                    elara = gcnew Elara(420, 1410);
                    return -1; 
                }
            }

            
            for (int i = 0; i < fragmentos->Count; i++) {
                if (fragmentos[i]->activo) {
                    if (rElara.IntersectsWith(fragmentos[i]->GetRectangulo())) {
                        
                        return fragmentos[i]->id;
                    }
                }
            }

            return 0;
        }

        
        void RecogerFragmento(int id) {
            for (int i = 0; i < fragmentos->Count; i++) {
                if (fragmentos[i]->id == id) {
                    fragmentos[i]->Desactivar();
                    fragmentosRecogidos++;
                    break;
                }
            }
        }

        bool NivelCompletado() {
            return fragmentosRecogidos >= 5;
        }

        void DibujarTodo(Graphics^ g) {
            escenario->Dibujar(g, camX, camY);

            // Dibujar libros
            for (int i = 0; i < fragmentos->Count; i++) {
                fragmentos[i]->Dibujar(g, camX, camY);
            }

            // Dibujar Sombras
            for (int i = 0; i < sombras->Count; i++) {
                sombras[i]->Dibujar(g, camX, camY);
            }

            elara->Dibujar(g, camX, camY);
            Pen^ p = gcnew Pen(Color::Red, 2);
            for (int i = 0; i < obstaculos->Count; i++) {
                // para dibujar las paredes correctamente, restamos la camara
                Rectangle r = obstaculos[i];
                r.X -= camX;
                r.Y -= camY;
                g->DrawRectangle(p, r);
            }
        }
        int GetCamX() { return camX; }
        int GetCamY() { return camY; }
    };
}