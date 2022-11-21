# Exrecise1.2-algos
על הגיט להכיל קובץ README שמסביר איך לקמפל ואיך להריץ את הקוד )על ידי פקודה לדוגמא( וכן
מסביר את המימוש שלכם ואילו אופטימיזציות הכנסתם אם בכלל. שימו לב שאם לא נצליח לקמפל
ולהריץ את הקוד- לא נוכל לבדוק, וודאו כי ההראות ברורות ופשוטות. חשוב שתהיה דוקומנטציה מלווה
גם בקוד עצמו. החשיבות של README בגיט היא עצומה, ויש לדאוג לפירוט הרב ביותר שניתן לתת -
דבר זה יובא לידי ביטוי בציון התרגיל. שימו לב- זהו פרוייקט מתגלגל. הקוד שלנו יצטרך לשבת בקוד
עתידי נוסף, לכן יש להקפיד על מבנה נוח להוספה ושינויים
**Compilation & Running**
in order to compile the code you need to enter the following:
1. g++ -std=c++11 "path/distanceAlgorithems.cpp" (enter)
2. ./a.out (enter) - command which will run the code.
3. enter first vector (each number seperated by a space), ENTER
4. enter second vector (each number seperated by a space), ENTER


**Code discription**
This code takes two vecotrs from the user input and calculates thier distance from each other using five diffrenet algorithems as desrcibed below.
in order to have independant functionality and generalized implementation, we divided the code into three main sections:
1. validation of user input.
2. an class\functions to calculate each algo.
3. another class\functions to apply universal vector manipulations needed for all of the algorithems.
a key concepte to separate the deduction of two vectors from the algorithems.

**validation**
two functions - 1. streaming a string, dividing between spaces.
                2. converting each string seperated by a space into a double variable (if valid).
                
**algorithems functionality**
key variables: Two const double vectors.
               one Vector which stands for the deduction of one from the second, (used in all of the algorithems). 
               m_diff vector -> each i place holds v1[i]-v2[i] 
algorithems: (psodue code)
1. euclidian() - sqrt(sum((v1[i]-v2[i])^2))
2. manhatan() - sum(|v1[i]-v2[i]|)
3. minkovsky(p) - (sum(|v1[i]-v2[i]|^p))^(1/p)
              p - set to be 2 -> returns euclidian distance.
4. Canberra() - sum(|v1[i]-v2[i]|/(|v1[i]| + |v2[i]|))
5. Cevichev() - max(|v1[i]-v2[i]|)

**Manipulation on vectors**
function to calculate m_diff key variable of the algorithems functionality.





