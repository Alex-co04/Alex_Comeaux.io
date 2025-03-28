 Application Programming Interface (API)
---

## Outgoing Messages

### Subsystem Status Code  
Message type for sending status code of subsystem "Z" to be displayed.


. | byte 1     | byte 2
-------|------------|---
Variable Name   | msg_type | error_code
Variable Type   | uint8_t (Z) | uint8_t
Min Value      | 4    | 0
Max Value      | 4    | 2

code number | meaning
---|---
0 | full functionality
1 | partial functionality
2 | no functionality


### Subsystem Error Message  
Message type for sending string about subsystem error.

.             | byte 1   | byte 2-58
--------------|----------|----------
Variable Name | msg_type | err_msg
Variable Type | uint8_t  | char array (uint8_t)
Min Value     | 5        | char[1]
Max Value     | 5        | char[57]
Example       | 5        | "sensor 1 read error"

## Received Messages

### Shift Motor  
Message type for sending a command to rotate base stepper "Y" degrees.

. | byte 1     
-------|------------
Variable Name    | degree_turn
Variable Type    | Y(uint8_t)
Min Value        | 0
Max Value        | 360

### Alignment Frequency
  
Message type for sending a command to set the panel alignment frequency "X" number of seconds.

. | byte 1     
-------|------------
Variable Name   | time 
Variable Type   | X(uint8_t) 
Min Value      | 0    
Max Value      | 600    
## MPLabX Code

[Software](./assets/documents/SolarArray.X.zip)
