# Exrecise1.2-algos   

**Compilation & Running**  
in order to compile and run the code you need to enter the following:
1. $ git clone "https://github.com/AlonLuboshitz/Exrecise1.2-algos.git"
2. enter username "your username"
3. enter password "your password"
after the project has been cloned, enter the following:
4. cd Exrecise1.2-algos/
5. $ git checkout **even_dereh_3**, ENTER
6. make ,ENTER    
 to run the server - 
7. ./server.out (port number)    
to run the client -
8. ./client.out (server ip) (server port number)    
in client:
run accord to server menu.
when input file path insert without "".
11. when finnished enter -  make clean    


**Code discription**   

**server**    
 The server waits infinitely for clients to connect with it. Can serve multiple clients at a time. The server sends to the client a menu with all the possible actions to be performed, and after getting the choise from the client, sends instruction accordinly.    
 Server's option menu:    
 1. upload an unclasiified csv data file (train file - clasiffied data file, test file - unclassified data file)   
 2. algorithem settings - (defaule: k = 5 , distance algo's name = AUC - if the user presses enter, keeps default, else - user can insert new values by order)     
 3. clasiffy data    
 4. display results    
 5. download results    
 8. exit
 
 KNN (K Nearest Neighbors) -
 this code designed for running on a csv file, searching for the K nearest neighbors according to an input vector, and returning the most common label from the KNN. 
 
 assumptions and default behavors:
 1. The csv file conatains data vectors, each vector has only one string label, and the rest of the variables are doubles.   
 vector without a label will be categorized as an invalid neighbor.  
 2. The user will enter 4 arguments as follows: a.out k filepath distancealgorithem  
 if any changes from this pattern accure, the user will be asked to reassign each argument.  
 3. The file path will be for a csv file 
 4. The k will be a positive integer - 0 will be considered as 1, any double will be rounded down to an integer.
 5. Distance algorithem name codes: AUC/MAN/CHB/CAN/MIN - auclidean will be the default if the code will not fit to any of the name codes.
 6. input vector will be all double vector
 7. Input vector's size = n, each vector in the CSV file's size = n+1 - each vector has one label, and the rest variables will be taken to calculate the distance from the input vector. if any vector's size != n+1, it will not be considered as a valid neighbor.

**validation**  
1. arguments validation
2. input string validation 
                
**Distance algorithems**   
(psodue code)
1. euclidian() - sqrt(sum((v1[i]-v2[i])^2))
2. manhatan() - sum(|v1[i]-v2[i]|)
3. minkovsky(p) - (sum(|v1[i]-v2[i]|^p))^(1/p)
              p - set to be 2 -> returns euclidian distance.
4. Canberra() - sum(|v1[i]-v2[i]|/(|v1[i]| + |v2[i]|))
5. Cevichev() - max(|v1[i]-v2[i]|)

**KNN work flow**
1. Get each vector from the csv file. 
2. Temp vector validation- checks if the vector has exactly one string, and save it as the vector label.
3. Remove the label from the vector and convert all variables to doubles.
4. if the temp vector has the same size as the input vector, calculate the distance from temp to input according to the distance algorithem.
5. Sort all the distances (ascending)
6. From the first k distances, get the most common label.      

**client**

The client prints all of the Server's messages, waits for input from the user acoordinly and sends it back to the server. 





