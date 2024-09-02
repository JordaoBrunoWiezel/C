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

/* c. [2] Implemente a função int calculate_parking_fee(int hours_parked) que calcula a taxa de 
estacionamento com base no número de horas estacionadas. A taxa é de R$ 5,00 por hora. Considere 
que uma hora parcial é cobrada como uma hora completa. */

int calculate_parking_fee(int hours_parked){

    const int rate_per_hour = 5;
    
    // Arredondar para cima, considerando que uma hora parcial é cobrada como uma hora completa
    int total_fee = (hours_parked + 1) * rate_per_hour;

    return total_fee;
}
