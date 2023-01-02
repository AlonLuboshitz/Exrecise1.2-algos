compile = g++ -std=c++11
all: distanceAlgorithems.o Euclidean.o Manhatan.o Minkovsky.o Chevichev.o Canberra.o CSVReader.o inputValidation.o KNN.o  VectorManipulator.o Server.o Client.o
	$(compile) distanceAlgorithems.o Euclidean.o Manhatan.o Minkovsky.o Chevichev.o Canberra.o CSVReader.o inputValidation.o VectorManipulator.o Client.o -o client.out
	$(compile) distanceAlgorithems.o Euclidean.o Manhatan.o Minkovsky.o Chevichev.o Canberra.o CSVReader.o inputValidation.o KNN.o VectorManipulator.o Server.o -o server.out
distanceAlgorithems.o Euclidean.o: distanceAlgorithems.cpp distanceAlgorithems.h Euclidean.cpp Euclidean.h
	$(compile) -c distanceAlgorithems.cpp Euclidean.cpp
Manhatan.o: Manhatan.cpp Manhatan.h
	$(compile) -c Manhatan.cpp
Minkovsky.o: Minkovsky.cpp Minkovsky.h
	$(compile) -c Minkovsky.cpp
Canberra.o: Canberra.cpp Canberra.h
	$(compile) -c Canberra.cpp
Chevichev.o: Chevichev.cpp Chevichev.h
	$(compile) -c Chevichev.cpp
CSVReader.o: CSVReader.cpp CSVReader.h
	$(compile) -c CSVReader.cpp
inputValidation.o: inputValidation.cpp inputValidation.h 
	$(compile) -c inputValidation.cpp
KNN.o: KNN.cpp KNN.h
	$(compile) -c KNN.cpp
VectorManipulator.o: VectorManipulator.cpp VectorManipulator.h
	$(compile) -c VectorManipulator.cpp
# main.o: main.cpp 
# 	$(compile) -c main.cpp
Server.o: Server.cpp Server.h
	$(compile) -c Server.cpp
Client.o: Client.cpp Client.h
	$(compile) -c Client.cpp

clean: 
	rm *.o server.out client.out



