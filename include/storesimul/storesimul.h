/** 
 *  @file           storesimul.h
 *  @author         Arella Matteo <br/>
 *                  (mail: arella.1646983@studenti.uniroma1.it)
 *  @date           2018
 *  @brief          Simulation data secure storing header file
 */

#ifndef _STORESIMUL_H_
#define _STORESIMUL_H_

/**
 *	@defgroup Storesimul_module Store simulation module
 *   @{
 */

/**
 *  @brief 		This struct has all simulation data to store.
 *	@warning	In your main file define a simulation_storage_s struct 
 * 				with all data to store
 */
struct simulation_storage_s;

typedef struct simulation_storage_s simulation_storage_t;

/**
 *  @brief      This function registers SIGINT handling for
 * 				graceful simulation stopping.
 *              
 *  @author     Arella Matteo <br/>
 *              (mail: arella.1646983@studenti.uniroma1.it)
 *
 *	@param[in]  simulation_storage_t*      	Simulation parameters to store
 *              
 *  @return 	Void.
 */
void create_simulation_storage(simulation_storage_t* params);

/**
 *  @brief      This function starts an atomic critical section for simulation.
 * 				Call it every time you have to ensure that the simulation must not
 * 				be interrupted.
 *
 * 	@warning	This function call must be followed by a \ref post_simulation() call
 * 				after the end of the critical section.
 *              
 *  @author     Arella Matteo <br/>
 *              (mail: arella.1646983@studenti.uniroma1.it)
 *              
 *  @return 	Void.
 */
void wait_simulation();

/**
 *  @brief      This function ends an atomic critical section for simulation.
 *
 * 	@warning	This function call must be preceded by a \ref wait_simulation() call.
 *              
 *  @author     Arella Matteo <br/>
 *              (mail: arella.1646983@studenti.uniroma1.it)
 *              
 *  @return 	Void.
 */
void post_simulation();

/**
 *  @brief      This function must be implemented to store simulation data.
 *
 *	@param[in]  simulation_storage_t*      	Simulation parameters to store
 *              
 *  @return 	Void.
 */
void store_simulation(simulation_storage_t* params);

/**
 *	@}
 */

#endif /* _STORE_SIMUL_H_ */