# The Raspberry Die Spoil Alert 

An IoT device that will measure ethylene levels inside a container to monitor for overripe fruits and vegetables and remind owners to use or compost their produce.  

Project completed by Team 6 at the Women Who Code IoT Hackathon on March 23 - 25, 2018.  
Team 6:  Nick Riehl, Janessa Munt, Julie Shih, Corey Stone, Jenna Tucker, and Oliver Fu.  

![alt text](/SpoilAlertTiny.png)

![alt text](/SpoilAlert1.jpg)

![alt text](/SpoilAlert2.jpg)

# Hardware list 

### Parts used in Spoil Alert: 

Assembled Feather HUZZAH w/ ESP8266 WiFi With Stacking Headers
Adafruit MiCS5524 CO, Alcohol and VOC Gas Sensor Breakout 
FeatherWing Doubler - Prototyping Add-on For All Feather Boards 
Adafruit 0.8" 8x16 LED Matrix FeatherWing Display - Red
Adafruit 0.54" Quad Alphanumeric FeatherWing Display - Red
Adafruit Parts Pal (bread board and wires)

### Unused parts provided:  
Adafruit Power Relay FeatherWing 
Micro servo 
PIR (motion) sensor 
Magnetic contact switch (door sensor) 
DHT22 temperature-humidity sensor + extras 


# Architecture Notes 

We started by connecting our Feather HUZZAH w/ ESP8266 WiFi to our Adafruit MiCS5524 CO, Alcohol and VOC Gas Sensor, and running a simple script, which provided a feed of ethylene detected in parts per million.  We tested our idea by comparing the read in the open air to a Ziplock bag filled with overripe fruits, which should have a high ethylene content.  This proved our foundational concept of sensing when produce gets near spoiling by monitoring ethylene in a vegetable drawer or other container.  

We then added the feature of having a text notice sent to warn owners of overripe produce.  To do this, we created a Linux server instance on AWS, deployed a website using Node.js and Express, and sent a GET request from our Arduino device to trigger a call to the Twilio API to send a text notice.

We connected the Adafruit 0.8" 8x16 LED Matrix FeatherWing Display to our Feather HUZZAH w/ ESP8266 WiFi to display a frowny face when ethylene gas levels reach a certain level.  We then added the Adafruit 0.54" Quad Alphanumeric FeatherWing Display to display the read in parts per million of ethylene being detected. We used the Arduino dashboard associated with our device to receive a feed of the gas sensor's readings and generate graphical representations of the changing data.  

We also created a simple front-end user interface where a user could enter their notice preferences associated with their Spoil Alert device.  

# Problems encountered 

Our biggest obstacle arose when we tried to send an API POST request from the Arduino device.  We found that a server layer was necessary to make this feasible.  

# Notes for future improvements

The code on our current device detects spoiling produce through a hardcoded number relative to the open air.  In a produce drawer or other container, the size of the container and amount of produce present would affect the gas level in parts per million without indicating spoilage.  A more ideal product would detect a slope where spoiling produce began to produce a rapidly increasing amount of gas.  This would take some further research and development.    

## Problem Statement:

Uneaten food is the single biggest component of municipal solid waste. In landfills, food gradually breaks down to form methane, a greenhouse gas that's at least 25 times more powerful than carbon dioxide. In terms of total mass, fresh fruits and vegetables account for the largest losses at the consumer level at 28 percent. Public awareness about food waste in the US is limited and is a huge contributor to the problem. One of the reasons food waste has become such a large problem is that it has not been effectively measured or studied. A comprehensive report on food losses in the US is needed to characterize and quantify the problem, identify opportunities and establish benchmarks against which progress can be measured. 

http://www.sustainabletable.org/5664/food-waste

## Team Goals: 

* Create an IoT device that will monitor Ethylene levels inside of a container that monitors rotting fruit. 
* This device will alert customers that they will need to consume or compost the food based on ethylene levels.

## Business Objectives
* Scale – We envision this technology being used in produce drawers in Smart Refrigerators and Rubber Maid Containers making them “Smart”
* Sustainability – We envision changing the behavior of consumers by allowing them to monitor the state of their food allowing consumers to meal plan and reduce food waste to landfills which reduces methane in the atmosphere. Our goal is to include a feature in the app that will inform the customer of how much methane the costumer has reduced in the atmosphere by consumer the food and not sending the food to a landfill. This will “nudge” consumers to change their behavior.
* Continuous Delivery – We intend to be agile and continuously integrate our technology into more products and continuously deliver more features over time. 

## Background

* The United States wastes roughly 40 percent of its food - the equivalent of about $165 billion per year. Food is wasted at every point along the food chain: on farms and fishing boats; during processing and distribution; in retail stores and restaurants; at home; and after it enters our trash cans. Of the estimated 133 billion pounds of food that goes to waste every year, much of it is perfectly edible and nutritious.
* USDA's Economic Research Service (ERS) defines food waste as "the component of food loss that occurs when an edible item goes unconsumed, as in food discarded by retailers due to color or appearance and plate waste by consumers
* In the US, an average family of four wastes 1,160 pounds of food annually, (about 25 percent of the food they buy), costing them $1,365 to $2,275 per year. In terms of total mass, fresh fruits and vegetables account for the largest losses at the consumer level (28 percent), followed by dairy (17 percent), meat (12 percent) and seafood (33 percent). Major contributors to household food waste include:
* Food Spoilage - About two-thirds of food waste at home is due to food not being used before it goes bad. Food spoilage at home occurs due to improper storage, lack of visibility in refrigerators, partially used ingredients and misjudged food needs.
* Over-Preparing - The remaining third of household food waste is the result of people cooking or serving too much food. Cooking portions have increased over time and large meals often include more food than we can finish. The Cornell Food and Brand lab found that since 2006, serving sizes in the classic cookbook The Joy of Cooking have increased 36 percent. In addition, people often forget to eat leftovers and end up throwing them away.
* Date Label Confusion - According to a 2013 study by Harvard Law School and the Natural Resources Defense Council (NRDC), an estimated 90 percent of Americans prematurely discard food due to confusion over the meaning of date labels (e.g., "sell by," "best if used by," "expires," etc.). In reality, "sell by" and "use by" dates are not federally regulated and only serve as manufacturer suggestions for peak quality. Research on date labeling from the UK suggests that standardizing food date labeling and clarifying its meaning to the public could reduce household food waste by as much as 20 percent.
* Overbuying - Sales on unusual products and promotions that encourage impulse and bulk food purchases at retail stores often lead consumers to purchase items that don't fit into their regular meal plans and spoil before they can be used.
* Poor Planning - Without meal plans and shopping lists, consumers often make inaccurate estimates of what and how many ingredients they will use during the week. Unplanned restaurant meals or food delivery can also lead to food at home going bad before it can be used.

http://www.sustainabletable.org/5664/food-waste

### Target Release: 
March 25, 2018 1:00PM PST

### Assumptions at project start:
* Time Crunch – We only have one weekend to complete the project (Certain to Happen)
* Technical Abilities (Likely to Happen)
* Research 
* Science (Plenty of resources available)
* Hardware has limitations (Data point can only go so high)

### User Stories
* A user would like to select the type of fruit they just bought for the container and monitor this fruit
* A user would like to view the progress of rot over time 
* A user would like to know how to view the data for this app
* The user would like to view this data on their phone/laptop
* A user would like to receive notifications before it is too late to eat the fruit

### Benefits
* Simple to use
* Place the monitoring device in a container with the produce you want to monitor
* Go online and enter your phone number to start receiving notifications
* Allows you to track data on your food waste to monitor and change your habits
* Reduces environmental impacts by reducing the release of methane gas into the atmosphere

### Presentation Judging Criteria
1. Submission of code: By 1PM on GitHub
2. Presentation Time: 3 min
3. Theme idea:
- How relevant is your product to theme of sustainability?
 
![alt text](/pic1.png)

12 Responsible Consumption
13 Climate Action


## Authors

Nick Riehl - Hardware, back-end, architecture.  

*"My favorite learning experience was working with the hardware and figuring out how to implement two displays." - Nick Riehl* 

Janessa Munt - Design, research, API.  

*"My favorite part was learning how to utilize the IoT technology." -Janessa Munt* 

Julie Shih - LED display, presentation, animation.  

*"My favorite part was setting up the LED display and learning how to use the Arduino device." - Julie Shih* 

Corey Stone - Presentation, dashboard, data display.  

*"My favorite part was discovering the dashboard and figuring out that we could get the data stream and also working with developers." - Corey Stone* 

Jenna Tucker - Project management, API, name and logo.  

*"My favorite part was working with hardware and software both for the first time and working with my team." -Jenna Tucker*

Oliver Fu - Front-end UI and branding.  

*"My favorite part was learning more about APIs and how they work." - Oliver Fu*


## Acknowledgments

* Women Who Code for hosting the Hackathon.  Thank you for taking such thoughtful consideration in planning and running this event!
* Sponsors of the Women Who Code IoT Hackathon.  Thank you for making this event possible!
* Mentors at the Women Who Code Hackathon.  Thank you for all your great help!  
* C2Sense @ http://ilp.mit.edu/images/conferences/2016/water/presentations/Schnorr.JWAFS.pdf for presentation materials we found during our research that confirmed our initial concept.  
