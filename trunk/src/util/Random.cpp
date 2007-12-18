#include "Random.h"

Random::Random() {
	randomSeed = getrand_seed();
}

Random::~Random() {
}

std::vector<double> Random::getrand_numbers(double min, double max, double precision, int nb_numbers) {
	std::vector<double> numbers = std::vector<double>();
	srand(getrand_seed());
	for(int i = 0; i < nb_numbers; ++i) {
		double rand = getrand_precision(min, max, precision);
		numbers.push_back(rand);
	}
	return numbers;
}

double Random::getrand_precision(double min, double max, double precision) {
	/* Calculate the cardinality of the set [min, max] */
	double set_cardinality = (max-min+precision)/precision;

	/* Calculate the position (from 0 to the cardinality-1) in the set of the discrete value we want, see header for rationale */
	int set_position = (int)((set_cardinality)*rand()/(RAND_MAX));
	while (set_position == set_cardinality ) {
		set_position = (int)((set_cardinality)*rand()/(RAND_MAX));
	}

	/* As an example with min=1, max=3, precision=0.5
	 we will have: set_cardinality=5 {1.0, 1.5, 2.0, 2.5, 3}
	 and if rand=3 we return 2.5 (1.0 has the position 0, 1.5 has the position 1, and so on */

	return min+set_position*precision;
}

unsigned int Random::getrand_seed() {
	int seed;
	FILE *fin;

	seed = ((int)(time((time_t*)NULL))) + ((int)clock());
	seed += getpid() + getppid()*256;

	fin = fopen("/dev/urandom", "r");
	if (fin != NULL) {
		seed += ((fgetc(fin)) << 24) + ((fgetc(fin))<<16)+(fgetc(fin) << 8)
				+fgetc(fin);

		fclose(fin);
	}
	if (seed <0)
		seed = -seed;

	return (unsigned int)seed;
}
