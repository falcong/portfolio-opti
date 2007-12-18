#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <vector>

class Random {
private:
	int randomSeed;
	
	/* Return a random seed to initialise the rand function */
	unsigned int getrand_seed();
public:
	Random();
	virtual ~Random();

	int getSeed() const;
	
	std::vector<double> getrand_numbers(double min, double max, double precision, int nb_numbers);
	double getrand_precision(double min, double max, double precision);
};

#endif /*RANDOM_H_*/
