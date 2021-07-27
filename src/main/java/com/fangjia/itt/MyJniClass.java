
package com.fangjia.itt;


public class MyJniClass{
    static{
        System.loadLibrary("ittjni");
    }
    public static void main(String[] args){
        System.out.println("java.library.path is " + System.getProperty("java.library.path"));
        ITT itt_inst = new ITT();
        ITT.hello(); //this is the way to call a static method

        ITT.itt_resume();
        //generate a vector of length=`size` random numbers

        //calculate the sum of this vector

        ITT.itt_pause();
    }
}
