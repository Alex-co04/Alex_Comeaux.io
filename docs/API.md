 Application Programming Interface (API)
---

## Team Member IDs
Name    | Subsystem | Address | Char Add
--------|-----------|-------- |---------
Alex | Actuator       | `0x63`  |  'c'
Aarshon | HMI     | `0x61`  |  'a'
Ian     | Sensor    | `0x69`  |  'i'
KD      | Websocket | `0x6B`  |  'k'

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


## Received Messages

### Shift Motor  
Message type for sending a command to rotate base stepper "Y" degrees.

. | byte 1     
-------|------------
Variable Name    | degree_turn
Variable Type    | Y(uint8_t)
Min Value        | 0
Max Value        | 360

Example message according to message structure:
AZic235YB


### Alignment Frequency
  
Message type for sending a command to set the panel alignment frequency "X" number of seconds.

. | byte 1     
-------|------------
Variable Name   | time 
Variable Type   | X(uint8_t) 
Min Value      | 0    
Max Value      | 600    

Example message according to message structure:
AZic3




# Message Structure Summary
 Byte Index |           Description              | Value Example |
 -----------|------------------------------------|---------------|
 [0]        | Start Byte 1                       |      'A'      |
 [1]        | Start Byte 2                       |      'Z'      |
 [2]        | Sender ID                          |      'c'      |
 [3]        | Receiver ID                        | 'a','k',etc.  |
 [4]        | msg_type                           |  `1` - `5`    |
 [5-n]      | Data / Message / Payload           |    Varies     |
 [n+1]      | End Byte 1                         |      'Y'      |
 [n+2]      | End Byte 2                         |      'B'      |



## MPLabX Code

[Software](./assets/documents/SolarArray.X.zip)
