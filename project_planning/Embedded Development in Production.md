When writing embedded system software, a number of factors and tradeoffs must be considered:
- Throughput: How much data does the system need to process in a short period of time? 
- Response: How fast does the system need to react to events? 
- Testability: What equipment is required to test embedded software? How is it setup?  
- Debugability: How can software be diagnosed or debugged without peripherals, such as screens or keyboards?  
- Reliability: How can embedded systems be developed or configured handle any situation or event without human intervention?
- Memory Space: What are the memory constraints? How much memory is required by the program for storage and how much can be allocated for future firmware updates?  
  What other data besides the program needs to be stored within memory? Is the data disposable/volatile/temporary or persistent in memory? 
  How much data is required to be stored?  
- Program Installation: What tools are required to upload, install, or "flash" software onto the embedded system?  
- Power Consumption: How much power will an embedded system consume? If battery powered or achieving power efficiency, how can power conservation be attained? 
- Processor Hogs: How can intensive computations requiring significant CPU time be reduced to mitigate the complexity of device response? (i.e. Laser printer microprocessor calculating how to layout black dots on paper while user expects immediate response of "printed paper.") 
- Cost: How can "low-cost" hardware affect the efficacy or create limitations on software?    

-- An Embedded Software Primer -- David E. Simon, Pg. 11 

Largest factor / challenge: change.
- Which constraints above will be problematic *later* in product development? 
- How will the application evolve over time and can/should the system support the change? (Hardware is not easy or cheap to upgrade or patch after manufacturing.)  

-- Making Embedded Systems -- Elecia White. Pg. 5
