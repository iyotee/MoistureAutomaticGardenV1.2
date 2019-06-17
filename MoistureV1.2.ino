/*********************************************************************************
 *                                                                              **
 *          ********************************************************            **
 *          *   Moisture capacitive sensor V1.2 Automatic garden   *            **             
 *          ********************************************************            **                             
 *                                                                              **
 *                                                                              **
 *  Author : Jérémy Noverraz                                                    **
 *  Version : 1.2                                                               **
 *  Date of creation : 17/06/2019 01:05AM UTC +1                                **
 *  Specification : Read a moisture capacitive sensor with an arduino uno       **     
 *                  and turn on a 230/5V relay after the soil reaches a         **
 *                  certain level of humidity                                   **
 *                                                                              **
 *********************************************************************************/


  /* * * * * * * * * * * * *
   * * * * * * * * * * * * *
   * *                   * *
   * *    VARIABLES      * * 
   * *                   * * 
   * * * * * * * * * * * * *
   * * * * * * * * * * * * */

  int analogPin = A0;
  int relay = 13;
  int moisture;
  int percentage;
  int D = 500;
  int irrigationTime = 8000; /*Temps d'irrigation à changer selon la capacité d'evacuation de votre pompe et donc de la quantitée d'eau nécéssaire lord d'un arrosage /*

  /* * * * * * * * * * * * * * * * * * * * * * 
   * * * * * * * * * * * * * * * * * * * * * *  
   * *                                     * *
   * *   VARIABLES POUR LA CALIBRATION     * * 
   * *                                     * * 
   * * * * * * * * * * * * * * * * * * * * * * 
   * * * * * * * * * * * * * * * * * * * * * */

   int map_low = 619; /* valeure maximal quand la sonde est à l'air libre */
   int map_high = 241; /* valeure maximal quand la sonde est trempé dans un verre d'eau */


void setup() {
Serial.begin(9600);
pinMode(relay, OUTPUT);
digitalWrite(relay, HIGH); /* On éteint la pompe */
delay(D);
} 
void loop() {

  moisture = analogRead(analogPin);
  Serial.print("Raw data: ");
  Serial.print(moisture);

  percentage = map(moisture, map_low, map_high, 0, 100); /* On utilise la fonction MAP pour mapé les raw data de la sonde vers une fourchette de pourcentage*/

  Serial.print( " | " );
  Serial.print(percentage);
  Serial.print(" %");
  Serial.println("");

  if (moisture > 500 ){
    digitalWrite(relay, LOW); /* Si le pourcentage est inférieur à 40% d'humidité, On allume la pompe */
    delay(irrigationTime);
    digitalWrite(relay, HIGH);
    }


  delay(1000);
  

}
