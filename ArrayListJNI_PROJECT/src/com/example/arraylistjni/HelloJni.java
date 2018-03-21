package com.example.arraylistjni;

import java.util.ArrayList;

public class HelloJni {
	static {
		System.loadLibrary("array");
	}

	public native void setUser(User user);

	public native User getUser();

	public native void setUserList(ArrayList<User> userList);

	public native ArrayList<User> getUserList();
}
