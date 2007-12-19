CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		portfolio-opti.o Problem.o LinearProblem.o DetQuadProblem.o Objective.o Solution.o Term.o Constraint.o Variable.o VariableBool.o VariableInt.o VariableFloat.o algo/Algo.o algo/SimulatedAnnealing.o util/FileParser.o util/Logger.o util/Random.o solver/Solver.o solver/LpsolveAdaptator.o 

LIBS =	../lib/liblpsolve55.so

TARGET =	../bin/portfolio-opti

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) -lm -ldl $(LIBS) 

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
