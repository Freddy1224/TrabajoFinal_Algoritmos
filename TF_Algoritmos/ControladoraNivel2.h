#pragma once
#include "Escenario2.h"
#include "Elara.h"
#include "Sombra.h"      
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

    public:
        ControladoraNivel2() {
            escenario = gcnew Escenario2();
            
            elara = gcnew Elara(100, 400);

            obstaculos = gcnew List<Rectangle>();
            sombras = gcnew List<Sombra^>();

            
            obstaculos->Add(Rectangle(400, 480, 350, 60));
            obstaculos->Add(Rectangle(0, 0, 800, 60));
            obstaculos->Add(Rectangle(0, 0, 25, 800));
            obstaculos->Add(Rectangle(777, 23, 50, 800));
            obstaculos->Add(Rectangle(0, 750, 800, 50));
            obstaculos->Add(Rectangle(30, 40, 200, 60));
            obstaculos->Add(Rectangle(25, 300, 25, 240));
            obstaculos->Add(Rectangle(175, 15, 165, 155));
            obstaculos->Add(Rectangle(290, 15, 165, 110));
            obstaculos->Add(Rectangle(458, 50, 12, 150));
            obstaculos->Add(Rectangle(480, 50, 350, 60));
            obstaculos->Add(Rectangle(754, 205, 23, 80));
            obstaculos->Add(Rectangle(554, 244, 77, 40));
            obstaculos->Add(Rectangle(554, 620, 100, 35));
            obstaculos->Add(Rectangle(25, 620, 125, 180));
            obstaculos->Add(Rectangle(300, 620, 150, 170));
            obstaculos->Add(Rectangle(394, 300, 400, 210));
            obstaculos->Add(Rectangle(394, 270, 75, 50));
            obstaculos->Add(Rectangle(200, 290, 200, 240));
            obstaculos->Add(Rectangle(750, 550, 23, 200));

            
            sombras->Add(gcnew Sombra(300, 200));
            sombras->Add(gcnew Sombra(600, 590));
            sombras->Add(gcnew Sombra(150, 600));
        }

        void MoverTodo(bool w, bool s, bool a, bool d) {
            escenario->Animar();

           
            elara->Mover(w, s, a, d, 800, 800, obstaculos);

            
            for (int i = 0; i < sombras->Count; i++) {
                sombras[i]->Perseguir(elara->GetX(), elara->GetY(), obstaculos);
            }

            
            VerificarColisiones();
        }

        
        void VerificarColisiones() {
            Rectangle rElara = elara->GetRectangulo();

            for (int i = 0; i < sombras->Count; i++) {
                // Si el rectángulo de Elara toca alguna sombra...
                if (rElara.IntersectsWith(sombras[i]->GetRectangulo())) {

                    
                    elara = gcnew Elara(100, 400);

                    
                  
                    break;
                }
            }
        }

        void DibujarTodo(Graphics^ g) {
            escenario->Dibujar(g);

            for (int i = 0; i < sombras->Count; i++) {
                sombras[i]->Dibujar(g);
            }

            elara->Dibujar(g);

            // DEBUG Paredes (Actívalo si necesitas verlas de nuevo)
            /*
            Pen^ p = gcnew Pen(Color::Red, 2);
            for(int i=0; i<obstaculos->Count; i++) {
                g->DrawRectangle(p, obstaculos[i]);
            }
            */
        }
    };
}