#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

// forward declarations
class Event;
class TimeoutEvent;
class SeizeEvent;
class Simulator;



class Entity
{
public:
	Entity(const Entity& other);

	std::string name;
	std::vector <Event*> entity_event_vec;
	TimeValueMonitor* monitor;
	double activation_time;
	Simulator* sim;
	bool leave;

	Entity(std::string ent_name, double activation): name(ent_name), monitor(new TimeValueMonitor()), activation_time(activation) {
		// set activation time
		monitor->record(activation, -999);
		leave = false;
	}

	void set_simulator(Simulator* sim_obj) {
		sim = sim_obj;
	}

	Event* get_event() {
		Event* ev = entity_event_vec.front();
		entity_event_vec.erase(entity_event_vec.begin());
		return ev;
	}

	~Entity();

	void add_timeout_event(double);
	void add_seize_event(std::string, double);
	void add_release_event(std::string, double);
	void add_skip_event(int);

};




#endif
