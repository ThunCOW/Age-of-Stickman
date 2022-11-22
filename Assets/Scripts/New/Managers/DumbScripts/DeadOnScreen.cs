using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class DeadOnScreen : MonoBehaviour
{
    public static List<RaycastHit2D> DeadUnitsOnScreen = new List<RaycastHit2D>();
    public int count = 0;
    
    public LayerMask layer;
    
    
    // Start is called before the first frame update
    void Start()
    {
        transform.parent = null;

        StartCoroutine(SearchDeadBody());
    }

    void FixedUpdate()
    {
        transform.position = new Vector3(GameManager.Instance.Player.transform.position.x, transform.position.y, transform.position.z);
    }

    IEnumerator SearchDeadBody()
    {
        while(true)
        {
            yield return new WaitForSeconds(1f);

            RaycastHit2D[] deadUnits = Physics2D.BoxCastAll(transform.position, new Vector2(25, 20), 0, Vector2.right, 0, layer);

            DeadUnitsOnScreen.Clear();
            DeadUnitsOnScreen.AddRange(deadUnits);
            count = DeadUnitsOnScreen.Count;
            
            yield return null;
        }
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireCube(transform.position, Vector3.one);
    }
}
