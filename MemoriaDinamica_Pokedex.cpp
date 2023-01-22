//1._Agregar pokemon. 2._Buscar pokemon. 3._Mostrar el nombre de todos los pokemons. 4._Salir.
//Heap Data Member Program
//LOBBY GAME
#include <iostream>
#include <string>

using namespace std;
//PLAYER CLASS
class Player
{
public:
    Player(const string& name = "");
    string GetName() const;
    Player* GetNext() const;
    void SetNext(Player* next);
private:
    string m_Name;
    //Se creo para apuntar a otro Player
    Player* m_pNext; //Pointer to next player in list
};
Player::Player(const string& name) :
    m_Name(name),
    //Apunta NULL
    m_pNext(0)
{}
string Player::GetName() const
{
    return m_Name;
}
Player* Player::GetNext() const
{
    return m_pNext;
}
void Player::SetNext(Player* next)
{
    m_pNext = next;
}


//LOBBY CLASS
class Lobby
{
    friend ostream& operator<<(ostream& os, const Lobby& aLobby);
public:
    Lobby();
    ~Lobby();
    void AddPlayer();
    void RemovePlayer();
    void Clear();
    void Search();
private:
    //Apunta al player que esté en el inicio de la fila
    Player* m_pHead;
};
//Constructor
Lobby::Lobby() :
    m_pHead(0)
{}
//Destructor
Lobby::~Lobby()
{

    Clear();
}
void Lobby::AddPlayer()
{

    cout << "Please enter the name of the new Pokemon: ";
    string name;
    cin >> name;
    Player* pNewPlayer = new Player(name);

    if (m_pHead == 0)
    {
        m_pHead = pNewPlayer;
    }

    else
    {

        Player* pIter = m_pHead;

        while (pIter->GetNext() != 0)
        {
            pIter = pIter->GetNext();
        }

        pIter->SetNext(pNewPlayer);
    }
}
void Lobby::RemovePlayer()
{
    if (m_pHead == 0)
    {
        cout << "The game lobby is empty. No one to remove!\n";
    }
    else
    {
        Player* pTemp = m_pHead;
        m_pHead = m_pHead->GetNext();
        delete pTemp;
    }
}
void Lobby::Clear()
{
    while (m_pHead != 0)
    {
        RemovePlayer();
    }
}
void Lobby::Search() {

    int i = 0;
    string Pokemons[] = {"Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", "Squirtle", "Wartortle", "Blastoise", };
    string search;
    bool compare = false;

    cout << endl << "Please enter the name of the initial Pokemon to see the stats: \n";
    cin >> search;

    //Busqueda Sencuencial
    while ((compare == false) && (i < 3)) {
        if (Pokemons[i] == search) {
            compare = true;
        }
        i++;
    }

    if (compare == false) {
        cout << "ERROR! Pokemon no identificado.";
    }
    else if (compare == true) {
        if (i == 1) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #001\n";
            cout << "HP = 45\n";
            cout << "Attack = 49\n";
            cout << "Defense = 49\n";
            cout << "Special Attack = 65\n";
            cout << "Special Defense = 65\n";
            cout << "Speed = 49\n";
        }
        else if (i == 2) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #002\n";
            cout << "HP = 60\n";
            cout << "Attack = 62\n";
            cout << "Defense = 63\n";
            cout << "Special Attack = 80\n";
            cout << "Special Defense = 80\n";
            cout << "Speed = 60\n";
        }
        else if (i == 3) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #003\n";
            cout << "HP = 80\n";
            cout << "Attack = 82\n";
            cout << "Defense = 83\n";
            cout << "Special Attack = 100\n";
            cout << "Special Defense = 100\n";
            cout << "Speed = 80\n";
        }
        else if (i == 4) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #004\n";
            cout << "HP = 39\n";
            cout << "Attack = 52\n";
            cout << "Defense = 43\n";
            cout << "Special Attack = 60\n";
            cout << "Special Defense = 50\n";
            cout << "Speed = 65\n";
        }else if (i == 5) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #005\n";
            cout << "HP = 58\n";
            cout << "Attack = 64\n";
            cout << "Defense = 58\n";
            cout << "Special Attack = 80\n";
            cout << "Special Defense = 65\n";
            cout << "Speed = 80\n";
        }
        else if (i == 6) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #006\n";
            cout << "HP = 78\n";
            cout << "Attack = 84\n";
            cout << "Defense = 78\n";
            cout << "Special Attack = 109\n";
            cout << "Special Defense = 85\n";
            cout << "Speed = 100\n";
        }
        else if (i == 7) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #007\n";
            cout << "HP = 44\n";
            cout << "Attack = 48\n";
            cout << "Defense = 65\n";
            cout << "Special Attack = 50\n";
            cout << "Special Defense = 64\n";
            cout << "Speed = 43\n";
        }
        else if (i == 8) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #008\n";
            cout << "HP = 59\n";
            cout << "Attack = 63\n";
            cout << "Defense = 80\n";
            cout << "Special Attack = 65\n";
            cout << "Special Defense = 80\n";
            cout << "Speed = 58\n";
        }
        else if (i == 9) {
            cout << "\n These are the stats of " << search << endl;
            cout << "pokedex_ID = #009\n";
            cout << "HP = 79\n";
            cout << "Attack = 83\n";
            cout << "Defense = 100\n";
            cout << "Special Attack = 85\n";
            cout << "Special Defense = 105\n";
            cout << "Speed = 78\n";
        }
    }
}

int main()
{
    Lobby myLobby;
    int choice;
    do
    {
        cout << myLobby;
        cout << "\nPOKEDEX LOBBY\n";
        cout << "0 - Turn Off Pokedex.\n";
        cout << "1 - Add a Pokemon to the Pokedex.\n";
        cout << "2 - Remove a Pokemon from the Pokedex.\n";
        cout << "3 - Clear Pokedex.\n";
        cout << "4 - Search an initial Pokemon.\n";
        cout << endl << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0: cout << endl << "Good-bye.\n"; break;
        case 1: myLobby.AddPlayer(); break;
        case 2: myLobby.RemovePlayer(); break;
        case 3: myLobby.Clear(); break;
        case 4: myLobby.Search(); break;
        default: cout << "That was not a valid choice.\n";
        }
    } while (choice != 0);

    //Mostrar lo que hay en el Lobby
    cout << myLobby;
}

//Con un cout << objeto va a mostrar todo lo que hay en el Lobby
ostream& operator<<(ostream& os, const Lobby& aLobby)
{
    Player* pIter = aLobby.m_pHead;
    os << "\nEsto es lo que hay en la Pokedex\n";
    if (pIter == 0)
    {
        os << "The PoKedex is empty.\n";
    }
    else
    {
        while (pIter != 0)
        {
            os << pIter->GetName() << endl;
            pIter = pIter->GetNext();
        }
    }
    return os;
}