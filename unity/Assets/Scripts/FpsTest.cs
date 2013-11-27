using UnityEngine;
using System.Collections;

public class FpsTest : MonoBehaviour {

	public GameObject targObj;
	int count=0;

	float m_updateInterval = 1.0f;  // 更新される頻度.
	float m_accumulated   = 0.0f;
	float m_timeUntilNextInterval; //  次の更新までの残り時間.
	int m_numFrames = 0;
	float fps;

	int defaultFps = 60;
	int thresholdFps = 30;

	bool thresholdFlg = false;
	int thresholdCount = 0;

	void Awake(){
		Application.targetFrameRate = defaultFps;
	}
	
	// Update is called once per frame
	void Update () {
	
		m_timeUntilNextInterval -= Time.deltaTime;
		m_accumulated += Time.timeScale / Time.deltaTime;
		++m_numFrames;

		if( m_timeUntilNextInterval <= 0.0 )
		{
			// FPSの計算と表示
			fps = m_accumulated / m_numFrames;

			if(count > 0 && !thresholdFlg && fps < thresholdFps){
				thresholdCount = count;
				thresholdFlg = true;
			}

			m_timeUntilNextInterval = m_updateInterval;
			m_accumulated = 0.0F;
			m_numFrames = 0;
		}
	}

	void OnGUI(){
/*
		if (GUI.Button (new Rect (10,10,150,100), "menu")){
			Application.LoadLevel("menu");
		}
		if (GUI.Button (new Rect (10,120,150,100), "+ 1")){
			instantiateObj(1);
		}
		if (GUI.Button (new Rect (170,120,150,100), "+ 10")){
			instantiateObj(10);
		}
		if (GUI.Button (new Rect (330,120,150,100), "+ 100")){
			instantiateObj(100);
		}
*/
		GUI.Label(new Rect (10,230,1000,20), "FPS:" + fps.ToString());
		GUI.Label(new Rect (10,250,1000,20), "COUNT:" + count.ToString());
		if(thresholdFlg){
			GUI.Label(new Rect (10,270,1000,20), "FPS fell below " + thresholdFps.ToString() + "!!!! COUNT:" + thresholdCount.ToString());
		}
	}

	void instantiateObj(int num){
		float f = 0;
		for(int i = 0; i < num; i++){
			f = count / 1000f;
			Instantiate(targObj, new Vector3(f, f, f), Quaternion.identity);
			count++;
		}
	}
}
