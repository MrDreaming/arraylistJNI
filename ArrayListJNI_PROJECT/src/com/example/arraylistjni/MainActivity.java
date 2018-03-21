package com.example.arraylistjni;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		ArrayList<User> userList;
		User user;
		user = new HelloJni().getUser();
		Log.i("MainActivity", "MainActivity.java : " + user.getId()+", "+user.getUserName()+", "+user.getAge()+", "+user.isMan());
		user.setAge(20);
		user.setUserName("MainActivity.java");
		new HelloJni().setUser(user);
		
		userList = new ArrayList<>();
		user = new User();
		user.setId(10);
		user.setAge(18);
		user.setMan(true);
		user.setUserName("Tom");
		userList.add(user);
		new HelloJni().setUserList(userList);
		/////////////////////////////////////////////////////
		userList = new HelloJni().getUserList();
		Log.i("MainActivity", "MainActivity.java:28 size=" + userList.size());
		for (User u : userList) {
			Log.i("MainActivity",
					"MainActivity.java : [" + u.getId() + "," + u.getUserName()
							+ "," + u.getAge() + "," + u.isMan() + "]");
		}

	}
	
}
