#pragma once
class Hechizo
{
private:
    bool Teletransporte = true;
    bool Curar = true;
    bool Bloquear = true;
    bool Revivir = true;

public:

    bool puedeteletransportar() const { return Teletransporte; }
    bool puedecurar() const { return Curar; }
    bool puedebloquear() const { return Bloquear; }
    bool puederevivir() const { return Revivir; }

    void gastarteletransporte() { Teletransporte = false; }
    void gastacurar() { Curar = false; }
    void gastarbloquear() { Bloquear = false; }
    void gastarrevivir() { Revivir = false; }

};