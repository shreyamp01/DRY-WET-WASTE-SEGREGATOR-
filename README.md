# DRY-WET-WASTE-SEGREGATOR-
A dry and wet waste segregator is fundamentally a hardware project that leverages various sensors to automatically distinguish between dry and wet waste. This system ensures efficient waste management by utilizing different types of sensors to detect the properties of waste and segregate it accordingly.

# Key Components and Sensors
 1. Ultrasonic Sensor
Function: Measures the distance between the sensor and the object (waste) by emitting ultrasonic waves and calculating the time taken for the echo to return.
Application: Used to detect the presence and size of waste items as they are introduced into the system. This helps in determining if the waste is within the range for processing and can also aid in controlling the movement of conveyor belts.
2. Soil Moisture Sensor
Function: Measures the moisture content of the material it comes into contact with.
Application: Key in distinguishing between dry and wet waste. Wet waste such as food scraps and organic material will have higher moisture content, which this sensor can detect, while dry waste like paper and plastic will have low or no moisture content.
 3. IR Sensor (Infrared Sensor)
Function: Detects the presence and properties of objects using infrared light.
Application: Used to identify the type of material based on its reflective properties. This sensor can help in distinguishing materials like plastic and metal, which have specific reflective characteristics, thus aiding in the segregation process.


# Working Principle
Waste Input: Mixed waste is placed into the input section.
Initial Detection:
The ultrasonic sensor detects the presence of waste and its size, ensuring it is within the processing range.
Moisture Detection:
The waste passes over the soil moisture sensor, which measures the moisture content. High moisture indicates wet waste, while low moisture indicates dry waste.
Material Identification:
The IR sensor scans the waste to determine its material properties, helping to distinguish between different types of dry waste.
Sorting and Segregation:
Based on the sensor data, the sorting mechanism is activated. Wet waste is directed into one bin, while dry waste is directed into another.
Final Collection: Segregated waste is collected in separate bins, ready for further processing like recycling or composting.
