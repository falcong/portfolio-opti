CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		portfolio-opti.o Problem.o LinearProblem.o DetQuadProblem.o Stock.o Objective.o Solution.o Term.o Constraint.o Variable.o VariableBool.o VariableInt.o VariableFloat.o algo/Algo.o algo/InitialSolver.o algo/NaiveAlgorithm.o util/FileParser.o util/Logger.o 

LIBS =

TARGET =	../bin/portfolio-opti

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
