#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

#include "GameEntity.h"
#include "Graphics/Window.h"

#define BONUS_SPEED 0.1

class Bonus : public GameEntity
{
    enum BonusType
    {
        LIFE,
        SHIELD,
    };

    int side;               //Lato in cui viene generato il bonus
    int type;               //Rappresenta il tipo di bonus
    void CoordGeneration(); //Genera le posizioni iniziali
    void SetDirection();    //Imposta una direzione in cui si sposta il bonus
    void SetType();         //Imposta il tipo di bonus
    void SetSide();         //Imposta il lato dello schermo in cui viene generato il bonus

    public:

    Bonus(Window*);
    bool Generation();      //Indica se è arrivato il momento di generare un nuovo bonus
    bool Remove();          //Verifica se il bonus deve essere eliminato
    void Move() override;
    void Draw() override;
    ~Bonus();
};

#endif // BONUS_H_INCLUDED
