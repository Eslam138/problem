/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2alg;

import java.util.Scanner;

/**
 *
 * @author MGTC
 */
public class Pb2ALG {

    /**
     * @param args the command line arguments
     */
    
    static void citiesNum(int numOfCities,int fuelCapacity,int fuelFromCity[],int fuelConsumption[]){
        int cityNum = 0;
        int fuelValue = 0;
        
        for (int i = 0; i < numOfCities; i++) {//the for loop here just bec if the while loop broke we don't
                                               //leave other cities, but if all cities didn't break, it will be used
                                               //only once
            int k = 0;
            while (k < numOfCities) {

                fuelValue += fuelFromCity[i];//adds up the total amount of fuel
                fuelValue = Math.min(fuelValue, fuelCapacity);//this to take only the up to the fuel capacity
                                                              //even if the city can give more

                if (fuelValue >= fuelConsumption[i]) {//as long as there's enough fuel, then consume
                    fuelValue -= fuelConsumption[i];
                } else {//if the fuel existing is less than the amout req to travel to the next city
                    fuelValue = 0;
                    break;
                }
                i++;
                k++;
            }

            if (k == numOfCities) {
                cityNum = i%numOfCities;
                System.out.print(cityNum);
            } else {
                cityNum = -1;
            }
        }

        int Result = 0;
        if (cityNum >= 0) {
            Result = 1;
            int answer[] = new int[numOfCities];
            answer[cityNum] = 0;
            for (int j = 0; j < numOfCities - 1; j++) {
                int i = (cityNum - j - 1 + numOfCities) % numOfCities;//insted of puttting i-- below
                //take min bet fuel given and fuel capacity and subtract fuel consumptio
                //this is more than or equal value of answer[i]
                if (Math.min(fuelFromCity[i], fuelCapacity) - fuelConsumption[i] >= answer[(i + 1) % numOfCities]) {
                    answer[i] = 0;
                    Result++;
                } else {
                    answer[i] = answer[(i + 1) % numOfCities] - (Math.min(fuelFromCity[i], fuelCapacity) - fuelConsumption[i]);
                }

            }
        }

        System.out.println("\nMximum number of cities that can be visited = "+Result);
    }
    
    public static void main(String args[]) {

    Scanner scanner = new Scanner(System.in);
    
    System.out.print("Enter Number of Cities: ");
    int numOfCities = scanner.nextInt();
    System.out.print("Enter Max Capacity of Tank: ");
    int fuelCapacity = scanner.nextInt();
    int fuelFromCity[] = new int[numOfCities];
    int fuelConsumption[] = new int[numOfCities];

    System.out.print("Enter Amount of Fuel From Each city: ");
    for (int i = 0; i < numOfCities; i++) {
        fuelFromCity[i] = scanner.nextInt();
    }

    System.out.print("Enter the Distance Between each City: ");
    for (int i = 0; i < numOfCities; i++) {
        fuelConsumption[i] = scanner.nextInt();
    }
    
    citiesNum(numOfCities,fuelCapacity,fuelFromCity,fuelConsumption);
}
    
}
