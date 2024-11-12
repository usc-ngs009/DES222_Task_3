//DES222 Flood/Fire Warning App
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <list>
using namespace std;

//Flood Warning Notification
string floodInfo = "A flood is a natural disaster that consists of water released from "
                   "its natural confines and encasing dry land\n"
                   "Floods commonly occur when heavy rainfall causes natural bodies of water to overflow.\n"
                   "https://www.ga.gov.au/education/classroom-resources/hazards/natural-hazards/flood\n";
string floodWarnHelp = "To limit how much a flood affects you, there are multiple steps that can be taken. For example, storing valuables above flood waters to ensure their safety, "
                       "knowing how to turn off gas, electricity and water when necessary, and preparing physical preventors such as sandbags or flood barriers. It is also important "
                       "to remember that if a road or area is flooded, do not try to traverse through it.\nAdditionally, you could also contact your local government or services such as the SES for help both before and after"
                       " any potential floods. https://www.ses.qld.gov.au/flood\n";
string floodUnlikelyMess = "The postcode you have inputted has a low likelihood of flooding. If you still have worries, QLD government has information on floods on their website."
                           "Additionally, feel free to input another postcode if interested.";

//Cyclone Warning Notification
string cycloneInfo = "Tropical cyclones are natural disasters that form over warm tropical waters. They can cause dangerous winds, flash flooding and, storms. Cyclones usually move over multiple days,"
                     "moving far distances, before dissipating over land or cold waters. Additionally, cyclone damage can be as minor as minimal house damage, to extreme damage with widespread destruction."
                     "https://www.ses.qld.gov.au/cyclone\n";
string cycloneWarningHelp = "If in an area that is cyclone-susceptible, there are many steps that should be taken. For example, one should tune in for warnings, secure any loose items in the house,"
                            " unplug and turn off electrical items, and stay in contact with family to ensure everyone is safe. In the case of more extreme cyclones, cyclone shelters are available to reside in."
                            "https://www.qld.gov.au/emergency/dealing-disasters/disaster-types/cyclone-severe-storm\n";
string cycloneUnlikely = "The postcode you have inputted has a low likelihood of cyclones. If you still have worries, QLD government has information on cyclones on their website.";


list <string> cycloneSusceptAreas = {"4871", "4810", "4805", "4740", "4874", "4892"};
list <string> unlikelyCyclone = {"4849", "4802", "4800", "4737", "4865", "4852", "4825", "4854", "4860", "4870",
                                 "4700", "4670", "4655", "4659", "4000", "4560", "9726", "4890", "4830", "4895", "4850", "4702",
                              "4703", "4715", "4630", "4803", "4741", "4804", "4213", "4002", "4873", "4887", "4807", "4824", "4823", "4822", "4818", "4816"};

list <string> floodSusceptAreas = {"4735", "4492", "4481", "4830", "4487", "4406", "4490", "4560", "4416",
                                "4650", "4854", "4850", "4807", "4114", "4873", "4825", "4482"};
list <string> unlikelyFloods = {"4477", "4480", "4730", "4809", "4754", "4488", "4721", "4702", "4420", "4491",
                                "4493", "4455", "4740", "4470", "4497", "4417", "4486", "4570", "4719", "4390", "4357", "4567",
                                "4311", "4519", "4562", "4350", "4472", "4605", "4720", "4580", "4310", "4001",
                                "4344", "4370", "4405", "4413", "4670", "4718", "4885", "4818", "4660", "4305", "4829", "4465",
                                "4568", "4581", "4422", "4462", "4731", "4728", "4724", "4557", "4561", "3929",
                                "3065", "4674", "4680", "4341", "4700", "4659", "4000", "4871", "4878", "4184", "4816", "4870",
                                "4865", "4285", "4805", "4824", "7215", "4133", "4454", "4510", "9726", "4823",
                                "4381", "4895", "4474", "4304", "4705", "4744", "4380", "4890", "4208", "4108", "4821", "4822",
                                "4814", "4307", "4859", "4407", "4467"};


int main() {
    string postcodeEntry;
    cout << "Please enter your desired postcode." << endl;
    getline(cin, postcodeEntry);
    cout << "Your postcode is: " << postcodeEntry << endl;
    /*Add code for sentence regarding whether postcode is flood/cyclone-susceptible
     * Then, add code connecting to flood/fire warning notif. paragraphs*/
    if (find(cycloneSusceptAreas.begin(), cycloneSusceptAreas.end(), postcodeEntry) != cycloneSusceptAreas.end()){
        cout << "This area is susceptible to cyclones.\n" + cycloneInfo + cycloneWarningHelp << endl;
    } else {
        cout << cycloneUnlikely << endl;
    }
    if (find(floodSusceptAreas.begin(), floodSusceptAreas.end(), postcodeEntry) != floodSusceptAreas.end()){
        cout << "This area is susceptible to floods.\n" + floodInfo + floodWarnHelp << endl;
    } else {
        cout << floodUnlikelyMess << endl;
    }
    return 0;
}

/*list of all postcodes used
 *4871, 4810, 4805, 4740, 4874, 4892, 4849, 4802, 4800, 4737, 4865, 4854, 4860, 4870, 4700, 4670, 4655, 4659, 4000, 4560, 9726, 4890, 4830, 4895, 4850,
 *4702, 4703, 4715, 4630, 4803, 4741, 4804, 4213, 4002, 4887, 4807, 4824, 4823, 4822, 4818, 4816, 4735, 4492, 4481, 4487, 4406, 4490, 4416,
 *4650, 4114, 4873, 4825, 4482,
 *4477, 4480, 4730, 4809, 4754, 4488, 4721, 4420, 4491, 4493, 4455, 4470, 4497, 4417, 4486, 4570, 4719, 4390, 4357, 4567, 4311, 4519, 4562, 4350,
 *4472, 4605, 4720, 4580, 4310, 4001, 4344, 4370, 4405, 4413, 4718, 4885, 4660, 4305, 4829, 4465, 4568, 4581, 4422, 4462, 4731, 4728, 4724, 4557,
 *4561, 3929, 3065, 4674, 4680, 4341, 4878, 4184, 4285, 7215, 4133, 4454, 4510, 9726, 4381, 4474, 4380, 4208, 4108, 4821, 4814, 4307, 4859, 4407, 4467*/

/*QLD cyclone postcodes:
 *2010 - 4871, 4849, 4810, 4805, 4740 (twice), 4802, 4800, 4737, 4865
 *2011 - 4805, 4810 (twice), 4740, 4852, 4825, 4852, 4854, 4860, 4849
 *2012 - 4874, 4870
 *2013 - 4892, 4740, 4700, 4670, 4655, 4659, 4000, 4560, 9726, 4810
 *2014 - 4810 (twice), 4740 (twice), 4805 (twice), 4892, 4890, 4871, 4830, 4895, 4850,4800
 *2015 - 4702, 4703, 4700, 4715, 4630, 4895
 *2016 - n/a
 *2017 - 4802, 4803, 4741, 4800, 4805, 4804, 4740, 4560, 4000, 4213, 4002
 *2018 - 4892, 4874, 4871, 4870, 4860, 4871, 4850
 *2019 - 4874, 4873, 4849, 4810, 4887, 4807, 4824, 4823, 4822, 4818, 4816, 4892, 4870*/

/*QLD flood postcodes:
 *2010 - 4477 (twice), 4480 (twice), 4730, 4735 (x3), 4809, 4754, 4488 (x3), 4721, 4702 (x5), 4420 (twice), 4492, 4491 (x3), 4493 (twice), 4455 (twice),
 * 4481, 4740 (twice), 4830 (x3), 4470 (twice), 4497 (twice),  4487, 4417, 4486 (twice), 4406, 4570, 4719, 4390, 4490, 4357, 4567, 4311, 4519, 4562, 4350, 4472,
 * 4605, 4720, 4580, 4310
 *2011 - 4001, 4344, 4570, 4560, 4370, 4405, 4413, 4416, 4670, 4420, 4719, 4718, 4702, 4885, 4818, 4660, 4830, 4829, 4455 (x3), 4417, 4390, 4487, 4486 (twice), 4465
 *2012 - 4477 (twice), 4492 (twice), 4829, 4568, 4581, 4465, 4487, 4455, 4470, 4497 (twice), 4422, 4417, 4462, 4488, 4486 (twice), 4490, 4491, 4493, 4480, 4472, 4731,
 * 4730, 4481, 4728, 4724, 4560 (twice), 4570, 4557, 4561, 4650, 3929, 3065
 *2013 - 4413, 4310 (twice), 4674, 4680 (twice), 4670, 4341, 4854 (twice), 4850, 4700, 4659, 4660, 4305, 4000, 4871, 4416, 4406, 4650, 4344
 *2014 - 4491, 4493, 4854 (twice), 4850 (twice) 4878, 4807, 4184, 4885, 4816, 4416, 4674, 4650, 4560, 4001, 4114, 4873, 4870, 4865, 4285, 4818, 4809, 4805
 *2015 - 4825, 4824, 4805, 4310 (twice), 7215, 4560, 4873 (twice), 4854, 4650, 4133, 4454, 4416 (twice), 4581, 4510, 4001, 4114, 9726, 4728, 4285
 *2016 - 4830 (twice), 4823, 4285, 4740, 4341, 4735 (x4), 4482, 4481, 4455, 4416, 4487, 4390 (x3), 4477, 4824, 4381, 4581, 4825 (x3), 4895, 4850, 4854, 4873, 4472,
 * 4492 (twice), 4807, 4700, 4474, 4304, 4705, 4744, 4406, 4380, 4114
 *2017 - 4830 (twice), 4305 (twice), 4890 (x3), 4208, 4807 (twice), 4871, 4490, 4492, 4108, 4735, 4825, 4821, 4822, 4700, 4114, 4809, 4805, 4670 (twice), 4674, 4406
 *2018 - 4873, 4807 (twice), 4184 (twice), 4854 (twice), 4814 (twice), 4454, 4413 (twice), 4650 (twice), 4114, 4307 (twice), 4859, 4850, 4824 4735, 4730,
 * 4870, 4482, 4493, 4416, 4370, 4407
 *2019 - 4807 (twice), 4873, 4895, 4816, 4809, 4482, 4481, 4492, 4490, 4477, 4467, 4825, 4735, 4702, 4341, 4108*/

