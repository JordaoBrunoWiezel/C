#define MAX_PARKING_SPOTS 200
#define EMPTY 0
#define OCCUPIED 1

typedef struct {
    int spot_number; // número da vaga
    int status; // EMPTY ou OCCUPIED
} ParkingSpot;

typedef struct {
    ParkingSpot spots[MAX_PARKING_SPOTS]; // vagas do estacionamento
    int num_spots; // número de vagas
} ParkingLot;

bool find_parking_spot(const ParkingLot *lot, int status, int *spot_number){

    for(int i= 0; i < lot -> num_spots; i++){
        if(lot->spots[i].status == status){
            *spot_number = lot->spots[i].spot_number;
            return true;
        }
    }

return false;
}

/* b. [1.5] Utilizando a função anterior, implemente a função int park_car(ParkingLot *lot) que procura 
o primeiro lugar livre para estacionar, marca o lugar como ocupado e retorna o número da vaga onde foi 
colocado o carro. Se o estacionamento estiver cheio, a função deve retornar -1.*/

int park_car(ParkingLot *lot){

    for(int i= 0; i < lot -> num_spots; i++){
        if(find_parking_spot(*lot, EMPTY, &i)){
            lot->spots[i].status = OCCUPIED;
            return i;
        }
    }

}

