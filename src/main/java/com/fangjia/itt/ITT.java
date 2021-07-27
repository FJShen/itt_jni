package com.fangjia.itt;


public class ITT{

  public static void itt_pause(){
      __itt_pause();
  }

  public static void itt_resume(){
      __itt_resume();
  }

  public static void itt_detach(){
      __itt_detach();
  }

  static {
      System.loadLibrary("ittjni"); //the JNI for ITT API
  }
  private native static void __itt_pause();
  private native static void __itt_resume();
  private native static void __itt_detach();
  public native static void hello();
}