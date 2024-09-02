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

/* a. [1.5] Implemente a função bool find_parking_spot(const ParkingLot *lot, int status, int *spot_number) que procura 
a partir da primeira vaga o primeiro lugar de estacionamento livre ou ocupado, de acordo com o indicado em status. Caso encontre, 
atualiza spot_number e retorna true; caso contrário, retorna false.*/

bool find_parking_spot(const ParkingLot *lot, int status, int *spot_number){

    for(int i= 0; i < lot -> num_spots; i++){
        if(lot->spots[i].status == status){
            *spot_number = lot->spots[i].spot_number;
            return true;
        }
    }

return false;
}