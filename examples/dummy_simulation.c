#include <stdio.h>
#include <stdint.h>
#include <storesimul/storesimul.h>

struct simulation_storage_s {
	int* array_1;
	int* array_2;
};

void store_simulation(simulation_storage_t* params) {
    printf("\rSalvo ed esco...bim\n");
}

int main(int argc, char** argv) {
    int a[] = {1,2,3};
    int b[] = {1,2,3};

    simulation_storage_t param = {	.array_1 = a,
                            		.array_2 = b};
    
    create_simulation_storage(&param, &store_simulation);
    
    // SIMULA TUTTE COSE
    uint32_t i, sim_num = 0;

    while(1) {
    	wait_simulation();

    	for (i = 0; i < 0xFFFF; i++) {
    		printf("Simulazione #%d: iterazione %d\n", sim_num, i);
    	}

    	post_simulation();

    	sim_num++;
    	for (i = 0; i < 0xFFFFFFF; i++) {
    		
    	}
    }

    return 0;
}
