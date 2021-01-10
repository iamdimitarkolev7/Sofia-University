# Ivan Markup Language

IML is a tag language. The idea is to enable the user to make mapping, aggregating and sorting operations over a valid sequence of double numbers. The aim of this project is to create a parser to that language and generate a result. If an error occurs it should be presented in the console.

### Tag structure
<**_tag name_** "**_tag parameter_**">**_sequence of values_**</**_tag name_**>
+ **_tag name_** is the name of the tag and it should be with capital letters only
+ **_tag parameter_** may be missed in some tags which does not support additional parameters
+ **_sequence of values_** must be a valid double number sequence

### IML Valid Tags

1. MAP TAG Category
    * <MAP-INC "**1**">**1 2 3**</MAP-INC> => **2 3 4** (increases each value inside the tag by the parameter)
    * <MAP-MLT "**2**">**1 2 3**</MAP-MLT> => **2 4 6** (multiplies each value inside the tag by the parameter)

2. AGG TAG Category
    * <AGG-SUM>**1 2 3**</AGG-SUM> => **6** (returns sum of all values inside of the tag) 
    * <AGG-PRO>**1 2 3**</AGG-PRO> => **6** (returns the product of all values inside of the tag)
    * <AGG-AVG>**1 2 3**</AGG-AVG> => **2** (returns the average between the values inside of the tag) 
    * <AGG-FST>**1 2 3**</AGG-FST> => **1** (returns the first element of the double number sequence inside of the tag)
    * <AGG-LST>**1 2 3**</AGG-LST> => **3** (returns the last element of the double number sequence inside of the tag)

3. SRT TAG Category
    * <SRT-REV>**1 2 3**</SRT-REV> => **3 2 1** (reverses the values inside of the tag)
    * <SRT-ORD "**ASC**">**3 2 1**</SRT-ORD> => **1 2 3** (sorts values in ascending order("ASC" param) or in descending order ("DSC" param)
    * <SRT-SLC "**1**">**3 2 1**</SRT-SLC> => **2 1** (returns sublist of values from the given index (param))
    * <SRT-DST>**4 8 4 3**</SRT-DST> => **4 8 3** (removes duplicates)
    
### Usage
When you run the program you should type two valid txt file names. The first one is the name of the input file and the second one is the output file name. If there are not any errors in the input file you can see the result in the output file. Otherwise, an error message should appear in the console telling you what is the exact error.

### Examples
Input in the console: `input.txt result.txt`<br/>
input.txt text: `<SRT-ORD "ASC">81.2 3<MAP-INC "-1.5">4 12.5 55<AGG-AVG>4 8</AGG-AVG></MAP-INC>22.45</SRT-ORD>`<br/>
result.txt text after execution: `2.5 3 4.5 11 22.45 53.5 81.2`<br/>

Input in the console: `invalid.txt result.txt`<br/>
input.txt text: `Hello, World!`<br/>
result.txt text after execution should be empty<br/>
error displayed in the console: `The IML must start with an opening tag!`<br/>
