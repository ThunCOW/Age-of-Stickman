using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ThrowSycthe : MonoBehaviour
{
    public Transform parent;
    public Transform target;

    public SpriteRenderer spriteRenderer;
    public Sprite effectSprite;
    public Sprite syctheSprite;

    float speedHit;
    public float hitTime;
    float speedBounce;
    public float bounceTime;
    public float catchHeigh;
    public float startHeight;
    public float heighIncrease;

    Rigidbody2D rb2d;
    float gravityForce;

    int direction = 1;                                              // Direction the sycthe will be thrown, direction the enemy(target) is standing relative to current unit(sycthe thrower)
    // Start is called before the first frame update
    void Start()
    {
        rb2d = GetComponent<Rigidbody2D>();
        gravityForce = rb2d.gravityScale * 9.81f;
        rb2d.gravityScale = 0;

        // Set parent and target objects
        parent = transform.parent;
        target = parent.GetComponent<Unit>().target.gameObject.transform;

        transform.parent = null;

        direction = parent.transform.position.x - target.transform.position.x < 0 ? 1 : -1;

        // speedHit = Distance / time
        speedHit = Mathf.Abs(parent.transform.position.x - target.transform.position.x) / hitTime;

        rb2d.velocity = new Vector2(speedHit * direction, 0);

        rb2d.AddTorque(800 * direction, ForceMode2D.Force);

        StartCoroutine(BounceAction());
        StartCoroutine(SpinSound());
    }

    IEnumerator SpinSound()
    {
        while(!isBounced)
        {
            SoundManager.Instance.PlayEffect(SoundManager.Instance.SyctheSpin[Random.Range(0, 2)]);
            yield return new WaitForSeconds(0.1f);
        }
    }

    bool isBounced = false;
    IEnumerator BounceAction()
    {
        if (direction == 1)
        {
            while (transform.position.x < (target.transform.position.x - 0.5f))
            {
                yield return null;
            }
        }
        else
        {
            while(transform.position.x > (target.transform.position.x + 0.5f))
            {
                yield return null;
            }
        }

        isBounced = true;

        spriteRenderer.sprite = syctheSprite;

        rb2d.velocity = Vector2.zero;
        rb2d.gravityScale = gravityForce / 9.81f;
        float verticalVelocity = Mathf.Sqrt(2 * (gravityForce / (bounceTime * bounceTime)) * heighIncrease) * (bounceTime * bounceTime);

        // force = Time * velocity
        float verticalForce = (float)verticalVelocity / (float)Time.fixedDeltaTime;

        rb2d.AddForce(Vector2.up * verticalForce);

        float horizontalVelocity = Mathf.Abs(transform.position.x - parent.position.x);

        rb2d.velocity = new Vector2(horizontalVelocity * direction * -1, 0);

        parent.gameObject.GetComponent<Unit>().unitController.DealDamage();

        StartCoroutine(WaitForReturn());

        yield break;
    }

    IEnumerator WaitForReturn()
    {
        spinSoundRetRoutin =  StartCoroutine(spinSoundReturn());
        if (direction == 1)
        {
            while (transform.position.x > (parent.transform.position.x + 0.3f))
            {
                yield return null;
            }
        }
        else
        {
            while (transform.position.x < (parent.transform.position.x - 0.3f))
            {
                yield return null;
            }
        }
        if (spinSoundRetRoutin != null)
            StopCoroutine(spinSoundRetRoutin);
        Destroy(this.gameObject);
        yield break;
    }

    Coroutine spinSoundRetRoutin = null;
    IEnumerator spinSoundReturn()
    {
        SoundManager.Instance.PlayEffect(SoundManager.Instance.SyctheSpin[Random.Range(0, 2)]);
        yield return new WaitForSeconds(0.1f);
    }
}
