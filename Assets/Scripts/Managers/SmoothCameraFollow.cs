using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion 
{ 
    public class SmoothCameraFollow : MonoBehaviour
    {
        public Transform target;
        public Vector3 offset;
        public float damping;

        private Vector3 velocity = Vector3.zero;
    
        void Start()
        {
            QualitySettings.vSyncCount = 0;
            Application.targetFrameRate = 60;

            target = GameManager.Instance.transform;
        }

        // Update is called once per frame
        void FixedUpdate()
        {
            Vector3 movePosition = target.position + offset;
            transform.position = Vector3.SmoothDamp(transform.position, movePosition, ref velocity, damping);
        }
    }
}