 <h2>The specs that were used to run the program are as follows:</h2>

    i.) CPU - AMD Ryzen 7 5800H with Radeon Graphics
    ii.) GPU - Nvidia Geforce RTX 3060 Laptop GPU

<h2>Comparative Execution Time</h2>

<h3>i.) Power of 20</h3>
<p align=center>---------- DEBUG ----------</p>
<img width="876" alt="20d" src="https://github.com/BroWayneco/LBYARCH-MCO/assets/72311925/ef912557-b7be-40c7-a629-5830a676db9c">

    Average Time in Assembly:0.000867
    Average Time in C:0.003167
<p align=center>---------- RELEASE ----------</p>
<img width="876" alt="20r" src="https://github.com/BroWayneco/LBYARCH-MCO/assets/72311925/53ac3228-e559-4804-bd10-8582badee335">

    Average Time in Assembly:0.001000
    Average Time in C:0.000833

<h3>i.) Power of 24</h3>
<p align=center>---------- DEBUG ----------</p>
<img width="876" alt="24d" src="https://github.com/BroWayneco/LBYARCH-MCO/assets/72311925/bd4bedf3-aa15-4544-86dc-c9802a28bb4c">

    Average Time in Assembly:0.013133
    Average Time in C:0.049433
<p align=center>---------- RELEASE ----------</p>
<img width="876" alt="24r" src="https://github.com/BroWayneco/LBYARCH-MCO/assets/72311925/707b1c0f-2043-4b8d-a681-98f0482cd22d">

    Average Time in Assembly:0.012767
    Average Time inC:0.012667

<h3>i.) Power of 30</h3>
<p align=center>---------- DEBUG ----------</p>
<img width="876" alt="30d" src="https://github.com/BroWayneco/LBYARCH-MCO/assets/72311925/703008ef-40f7-442b-aba6-583bfba808b3">

    Average Time in Assembly:0.856406
    Average Time in C: 3.125767
<p align=center>---------- RELEASE ----------</p>
<img width="876" alt="30r" src="https://github.com/BroWayneco/LBYARCH-MCO/assets/72311925/8d79550c-1b02-4e27-aa68-88a003983d3c">

    Average Time in Assembly: 1.278967
    Average Time inC:0.784633

<h2>Short Analysis of the Performance of the Kernel</h2>

<p align=center>
Across all of the inputs sizes of 20, 24 and 30 and configuration, the result from assembly implementation consistently outperforms the c implementation in terms of the execution time.
</p>
<p align=center>
In the debug configuration, the performance of the two are significant especially as the value of the power increases the difference of the two becomes significant. 
</p>
<p align=center>
In the release configuration, the performance of the two can still be seen but less noticable compared to debug configuration.
</p>
<p align=center>
The performance from using assembly is more noticeable as the input size increases. This shows that the assembly implementation is more efficient compared to c implementation, especially when dealing with larger datasets.
</p>
<p align=center>
In conclusion, the assembly implementation of the kernel is better in terms of performance compared to the C implementation. 
It also shows the efficiency side of it and the effectiveness of optimizing the code using programming languages such as assembly when performance is crucial.
</p>



    
